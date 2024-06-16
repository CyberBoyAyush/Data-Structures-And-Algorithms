import os

def generate_index():
    with open('index.txt', 'w') as f:
        for root, dirs, files in os.walk('.'):
            for file in files:
                if '.git' not in root:  # Exclude .git directory
                    file_path = os.path.join(root, file)
                    f.write(file_path + '\n')

if __name__ == "__main__":
    generate_index()
