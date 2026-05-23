import heapq

CHUNK_SIZE = 4

def create_sorted_runs(input_file):
    with open(input_file, "r") as file:
        data = list(map(int, file.read().split()))

    run_index = 0

    for i in range(0, len(data), CHUNK_SIZE):
        chunk = data[i:i + CHUNK_SIZE]
        chunk.sort()

        with open(f"run{run_index}.txt", "w") as run_file:
            run_file.write(" ".join(map(str, chunk)))

        run_index += 1

    return run_index


def merge_runs(total_runs, output_file):
    run_arrays = []

    for i in range(total_runs):
        with open(f"run{i}.txt", "r") as file:
            run_arrays.append(
                list(map(int, file.read().split()))
            )

    merged = list(heapq.merge(*run_arrays))

    with open(output_file, "w") as output:
        output.write(" ".join(map(str, merged)))


with open("input.txt", "w") as file:
    file.write("8 3 7 4 9 2 6 1")

total_runs = create_sorted_runs("input.txt")

merge_runs(total_runs, "sorted_output.txt")

print("External Merge Sort completed.")
print("Check sorted_output.txt")
