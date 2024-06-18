import os

def generate_file_index(root_dir):
    file_tree = {}
    for dirpath, _, filenames in os.walk(root_dir):
        rel_dir = os.path.relpath(dirpath, root_dir)
        if rel_dir == ".":
            rel_dir = ""
        for filename in filenames:
            if filename != 'README.md':  # Exclude the README itself
                file_path = os.path.join(rel_dir, filename)
                dirs = rel_dir.split(os.sep) if rel_dir else []
                node = file_tree
                for d in dirs:
                    if d not in node:
                        node[d] = {}
                    node = node[d]
                node[filename] = file_path
    return file_tree

def render_file_tree(file_tree, base_path=""):
    md_lines = []
    for key, value in sorted(file_tree.items()):
        if isinstance(value, dict):
            md_lines.append(f'<details><summary>{key}</summary>')
            md_lines.append(render_file_tree(value, base_path + key + '/'))
            md_lines.append('</details>')
        else:
            md_lines.append(f'- [{key}]({base_path + key})')
    return '\n'.join(md_lines)

def update_readme(file_tree, readme_path='README.md'):
    with open(readme_path, 'r') as file:
        lines = file.readlines()

    start_marker = '<!-- FILE_INDEX_START -->'
    end_marker = '<!-- FILE_INDEX_END -->'

    start_index = next((i for i, line in enumerate(lines) if start_marker in line), None)
    end_index = next((i for i, line in enumerate(lines) if end_marker in line), None)

    if start_index is not None and end_index is not None:
        file_tree_md = render_file_tree(file_tree)
        lines = lines[:start_index + 1] + [file_tree_md + '\n'] + lines[end_index:]

        with open(readme_path, 'w') as file:
            file.writelines(lines)

if __name__ == "__main__":
    root_directory = '.'
    file_tree = generate_file_index(root_directory)
    update_readme(file_tree)
