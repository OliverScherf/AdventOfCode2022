# source: https://github.com/lefticus/cppbestpractices/blob/master/02-Use_the_Tools_Available.md
add_definitions(
        -Wall
        -Werror=return-type
        -Wnon-virtual-dtor # warn the user if a class with virtual functions has a non-virtual destructor. This helps
        # catch hard to track down memory errors
        -Woverloaded-virtual # warn if you overload (not override) a virtual function
        -Wunused # warn on anything being unused
        -Wnull-dereference # warn if a null dereference is detected
        -Wdouble-promotion # warn if float is implicit promoted to double
        -Wimplicit-fallthrough # warn on statements that fallthrough without an explicit annotation
        -Wshadow # warn the user if a variable declaration shadows one from a parent context
        -Wold-style-cast # warn for c-style casts
        -Wcast-align # warn for potential performance problem casts
        -Wextra # reasonable and standard
        -Wpedantic # warn if non-standard C++ is used
        -Wconversion # warn on type conversions that may lose data
        -Wsign-conversion # warn on sign conversions
        -Wformat=2 # warn on security issues around functions that format output (ie printf)
        -Wmisleading-indentation # warn if indentation implies blocks where blocks do not exist
        -Wduplicated-cond # warn if if / else chain has duplicated conditions
        -Wduplicated-branches # warn if if / else branches have duplicated code
        -Wlogical-op # warn about logical operations being used where bitwise were probably wanted
        -Wuseless-cast # warn if you perform a cast to the same type
)
