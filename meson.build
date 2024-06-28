project('cpp_module_demo_by_meson', 'cpp',
        version : '1.0.0',
        default_options : ['warning_level=3', 'cpp_std=c++latest']
)

# dependency
fmt = subproject('fmt')
fmt_dep = fmt.get_variable('fmt_header_only_dep')

# executable
meson_demo = executable('main', 'main.cpp',
                        cpp_args : ['/experimental:module'],
                        dependencies : [fmt_dep],
                        install : true)

# test
test('test', meson_demo)