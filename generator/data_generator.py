import random

def generate_job_data(num_jobs, min_duration, max_duration):
    jobs = []
    for i in range(num_jobs):
        duration = random.randint(min_duration, max_duration)
        jobs.append((i, duration))
    return jobs

def write_job_data_to_file(jobs, num_processors, filename):
    with open(filename, 'w') as f:
        f.write(f"{len(jobs)} {num_processors}\n")
        for job_id, duration in jobs:
            f.write(f"{duration}\n")

# Parametry generowania danych
num_jobs = 100  # Liczba zadań
num_processors = 5  # Liczba procesorów
min_duration = 10  # Minimalny czas trwania zadania
max_duration = 100  # Maksymalny czas trwania zadania

# Generowanie danych
jobs = generate_job_data(num_jobs, min_duration, max_duration)

# Zapis danych do pliku
write_job_data_to_file(jobs, num_processors, f".\\data\\jobs_data_{num_jobs}_{num_processors}_{min_duration}_{max_duration}.txt")
