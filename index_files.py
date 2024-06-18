import os
import pathlib
import datetime

# Configuration
REPO_URL = "https://github.com/CyberBoyAyush/Data-Structures-And-Algorithms"  # Update with your repo URL
EXCLUDE_FILES = ["README.md", "index_files.py", ".gitignore", ".vscode"]
EXCLUDE_EXTENSIONS = [".exe"]
GITHUB_RAW_URL = "https://raw.githubusercontent.com/CyberBoyAyush/Data-Structures-And-Algorithms/main/"  # Update with your raw repo URL

# Update last updated timestamp
now = datetime.datetime.now()
last_updated = now.strftime("%d %b'%y")

# Base content of README
base = f"""# 🍵 Some basic C++ programs

### These are some programs I make while I learn C++.
`Last Updated: {last_updated}`

"""

markup = "### List of all programs:\n"

def get_sorted_files(folder: str):
    """This sorts the inner files in ascending order"""
    files = os.listdir(folder)
    files = [x for x in files if x not in EXCLUDE_FILES]
    files = [x for x in files if not any(x.endswith(ext) for ext in EXCLUDE_EXTENSIONS)]
    files = sorted(files)
    return files

def get_name_and_path(folder: str = ".", level: int = 0):
    global markup
    
    for file in get_sorted_files(folder):
        filepath = os.path.join(folder, file)
        rel_path = os.path.relpath(filepath, ".")

        # Convert backslashes to slashes for GitHub URLs
        url_path = rel_path.replace("\\", "/")

        indent = '  ' * level
        if os.path.isdir(filepath):
            markup += f"{indent}<details>\n"
            markup += f"{indent}<summary>{file}</summary>\n"
            get_name_and_path(filepath, level + 1)
            markup += f"{indent}</details>\n"
        else:
            markup += f"{indent}- [{file}]({REPO_URL}/blob/main/{url_path})\n"

def get_extra_info():
    path = pathlib.Path('./')
    lines = 0
    files = 0
    char = 0
    for item in path.rglob('*.cpp'):
        files += 1
        with item.open() as of:
            for line in of.readlines():
                line = line.strip()
                lines += 1
                char += len(line)
    return f"- Total files: `{files:,}`\n- Total lines: `{lines:,}`\n- Total characters: `{char:,}`\n\n"

if __name__ == "__main__":
    get_name_and_path()
    with open("README.md", "w", encoding="utf-8") as f:
        f.write(base + get_extra_info() + markup)
