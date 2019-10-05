add_library(CalcLibrary calc.h)
install (TARGETS include DESTINATION bin)
install (FILES calc.h DESTINATION include)
