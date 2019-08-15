win32: SONAME=dll
else:  SONAME=so

# This function sets up the dependencies for libraries that are built with
# this project.  Specify the libraries you need to depend on in the variable
# DEPENDENCY_LIBRARIES and this will add
for(dep, DEPENDENCY_LIBRARIES) {
    message($$TARGET depends on $${PWD}/$$dep ($${PWD}/$${dep}/lib$${dep}.$${SONAME}))
    LIBS += "-L$${PWD}/$${dep}/bin/" -l$${dep}
    PRE_TARGETDEPS += $${PWD}/$${dep}/bin/lib$${dep}.$${SONAME}
}