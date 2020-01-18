gtest = dependency('gtest', main: true)

subdir('task_3')

test(
	'task_3',
	executable(
		'task_3_test',
		sources: ['Source_test.cpp'],
		include_directories: src,
		dependencies: [gtest]
	)
)
