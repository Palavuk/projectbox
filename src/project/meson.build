subdir('task_2')
subdir('task_3')
subdir('task_10')
subdir('task_4')
subdir('task_5')

tasks_src = files([
   'main.cpp',
])
executable(
    'project',
    include_directories: src,
    sources: tasks_src,
    link_with: [vector_lib, variadic_lib],
    install: true
)
