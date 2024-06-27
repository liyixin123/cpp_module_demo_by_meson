project('cpp_module_demo_by_meson', 'cpp',
        version : '1.0.0',
        default_options : ['warning_level=3', 'cpp_std=c++latest']
)

fmt = subproject('fmt')
fmt_dep = fmt.get_variable('fmt_header_only_dep')

meson_demo = executable('cpp_module_demo_by_meson', 'main.cpp',
                        cpp_args : ['/experimental:module'],
                        dependencies : [fmt_dep],
                        install : true)


test('test', meson_demo)