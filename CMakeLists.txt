prefix=@PREFIX@
    exec_prefix=${prefix}
    libdir=${exec_prefix}/lib
    includedir=${prefix}/include

    Name: everyutil
    Description: A portable C utility library
    Version: 1.0.0
    Cflags: -I${includedir}
    Libs: -L${libdir} -leveryutil