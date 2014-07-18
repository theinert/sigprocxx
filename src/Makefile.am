CLEANFILES = *.d *.so *_rdict.cxx *_rdict.h *rdict.pcm
MAINTAINERCLEANFILES = Makefile.in

# EXTRA_DIST = some extra files, e.g. test-data

lib_LTLIBRARIES = libsigprocxx.la

libsigprocxx_la_SOURCES = \
	comprehensions.cxx \
	filters.cxx \
	util.cxx \
	windowfcts.cxx \
	Dither.cxx \
	Filter.cxx \
	VectorOps.cxx \
	VectorView.cxx \
	VLEncoding.cxx \
	ZigZagEnc.cxx

libsigprocxx_la_headers = \
	comprehensions.h \
	filters.h \
	util.h \
	windowfcts.h \
	Dither.h \
	Filter.h \
	VectorOps.h \
	VectorView.h \
	VLEncoding.h \
	ZigZagEnc.h

pkginclude_HEADERS = $(libsigprocxx_la_headers)

# bin_PROGRAMS = 

# noinst_PROGRAMS =


libsigprocxx_la_linkdefs =

if WITH_BLITZWAVE
libsigprocxx_la_SOURCES += WlDecomp.cxx
libsigprocxx_la_headers += WlDecomp.h
libsigprocxx_la_linkdefs += sigprocxx-LDefs-wavelet.h
endif # WITH_BLITZWAVE







rootmapdir = $(libdir)
rootmap_DATA =


libsigprocxx_la_SOURCES += libsigprocxx_rdict.cxx
rootmap_DATA += .libs/libsigprocxx.rootmap


libsigprocxx_la_headers+=$(libsigprocxx_la_linkdefs)	
if WITH_CLING

rootmap_DATA += .libs/libsigprocxx_rdict.pcm
libsigprocxx_rdict.cxx: $(libsigprocxx_la_headers) sigprocxx-LinkDef.h
	$(ROOTCLING) -f $@.tmp -s libsigprocxx@SHLIBEXT@ -rml libsigprocxx@SHLIBEXT@ -rmf libsigprocxx.rootmap -c $(CPPFLAGS) $(CXXFLAGS) -I$(includedir) $+
	@# Some magic to prefix header names with "$(PACKAGE)/", and only that, in dictionary and rootmap:
	$(GREP) -F -v '"'"`pwd`"'/",' $@.tmp | $(SED) 's|"\([^"]*/\)\?\([^/"]*[.]h\)",|"'$(PACKAGE)/'\2",| ; s|\\"\([^"]*/\)\?\([^/"]*[.]h\)\\"\\n"|\\"'$(PACKAGE)/'\2\\"\\n"|' > $@ && $(RM) $@.tmp
	$(SED) 's|\(header \+\)\([^ ].*/\)\?\([^ ].*[.]h\)|\1'$(PACKAGE)/'\3|' -i libsigprocxx.rootmap

.libs/libsigprocxx.rootmap: libsigprocxx.la
	cp libsigprocxx.rootmap libsigprocxx_rdict.pcm .libs/

.libs/libsigprocxx_rdict.pcm: .libs/libsigprocxx.rootmap

else # not WITH_CLING

libsigprocxx_rdict.cxx: $(libsigprocxx_la_headers) sigprocxx-LinkDef.h
	$(ROOTCINT) -f $@ -c -p $(CPPFLAGS) `echo $(CXXFLAGS) | sed 's/\(^\|\s\)\(-std=[A-Za-z0-9+]\+\)\($$\|\s\)/\1\3/g'` $+

.libs/libsigprocxx.rootmap: libsigprocxx.la | $(libsigprocxx_la_headers) 
	$(RLIBMAP) -o $@ -l .libs/libsigprocxx@SHLIBEXT@ -c $|
	
endif # WITH_CLING