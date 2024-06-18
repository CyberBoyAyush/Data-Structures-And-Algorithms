import os

def generate_file_index(root_dir):
    file_list = []
    for dirpath, _, filenames in os.walk(root_dir):
        for filename in filenames:
            if filename != 'README.md':  # Exclude the README itself
                filepath = os.path.relpath(os.path.join(dirpath, filename), root_dir)
                file_list.append(filepath)
    return file_list

def update_readme(file_list, readme_path='README.md'):
    with open(readme_path, 'r') as file:
        lines = file.readlines()

    start_marker = '<!-- FILE_INDEX_START -->'
    end_marker = '<!-- FILE_INDEX_END -->'

    start_index = next((i for i, line in enumerate(lines) if start_marker in line), None)
    end_index = next((i for i, line in enumerate(lines) if end_marker in line), None)

    if start_index is not None and end_index is not None:
        lines = lines[:start_index + 1] + [f'- {file}\n' for file in file_list] + lines[end_index:]

        with open(readme_path, 'w') as file:
            file.writelines(lines)

if __name__ == "__main__":
    root_directory = '.'
    files = generate_file_index(root_directory)
    update_readme(files)
