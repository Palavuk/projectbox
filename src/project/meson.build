subdir("task 2")
subdir("task 3")

tasks_src = files([
    'main.cpp'
])
executable(
    'project',
    include_directories: src,
    sources: tasks_src,
    link_with: [vector_lib, variadic_lib, lock_guard_lib],
    install: true
)