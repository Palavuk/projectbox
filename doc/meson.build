doxyfile = configuration_data()
doxyfile.set('OUTPUT_DIRECTORY', join_paths(meson.build_root(), 'doc'))
doxyfile.set('EXTRACT_ALL', 'YES')
input_files = [join_paths(meson.source_root(), 'src', 'project', 'task_3'),]
    doxyfile.set('INPUT', ' '.join(input_files))
configure_file(input: 'Doxyfile.in', output: 'Doxyfile', configuration: doxyfile)
    doxygen = find_program('doxygen')
if doxygen.found()
    message('doxygen ' + join_paths(join_paths(meson.build_root(), 'doc'), 'Doxyfile'))
    run_target('doc', command: [doxygen, join_paths(meson.build_root(), 'Doxyfile')])
endif