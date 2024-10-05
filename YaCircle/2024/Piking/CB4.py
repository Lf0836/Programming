def convert_to_list(string: str) -> list:
  return [char for char in string]
def extract_last_chars(matrix: list) -> list:
  return [row[-1] for row in matrix]
def extract_first_chars(matrix: list) -> list:
  return [row[0] for row in matrix]
def trim_matrix(matrix: list) -> list:
  while "#" not in matrix[-1]:
      matrix.pop()
  while "#" not in matrix[0]:
      matrix.pop(0)
  while "#" not in extract_last_chars(matrix):
      matrix = [row[:-1] for row in matrix]
  while "#" not in extract_first_chars(matrix):
      matrix = [row[1:] for row in matrix]
  return matrix
def transpose_and_reverse(matrix: list) -> list:
  return [list(row)[::-1] for row in zip(*matrix)]
def matrices_are_equal(matrix1: list, matrix2: list) -> bool:
  for _ in range(4):
    if matrix1 == matrix2:
      return True
    matrix1 = transpose_and_reverse(matrix1)
  return False
row_count = int(input())
matrix1 = [convert_to_list(input().strip()) for _ in range(row_count)]
matrix2 = [convert_to_list(input().strip()) for _ in range(row_count)]
matrix1 = trim_matrix(matrix1)
matrix2 = trim_matrix(matrix2)
if matrices_are_equal(matrix1, matrix2):
  print("YES")
else:
  print("NO")
