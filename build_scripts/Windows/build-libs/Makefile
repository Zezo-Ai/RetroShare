ZLIB_VERSION=1.2.11
BZIP2_VERSION=1.0.8
MINIUPNPC_VERSION=2.2.3
OPENSSL_VERSION=1.1.1w
SPEEX_VERSION=1.2.1
SPEEXDSP_VERSION=1.2.1
LIBXML2_MAIN_VERSION=2.14
LIBXML2_VERSION=$(LIBXML2_MAIN_VERSION).5
LIBXSLT_MAIN_VERSION=1.1
LIBXSLT_VERSION=$(LIBXSLT_MAIN_VERSION).43
CURL_VERSION=8.9.1
TCL_VERSION=8.6.10
SQLCIPHER_VERSION=4.5.0
FFMPEG_VERSION=4.4.6
RAPIDJSON_VERSION=1.1.0
XAPIAN_VERSION=1.4.29
ASIO_VERSION=1-34-2
#RNP_VERSION=0.17.1

# libaries for rnp
JSON_C_VERSION=0.18
BOTAN_VERSION=2.19.5

DOWNLOAD_PATH?=download
BUILD_PATH=build
LIBS_PATH?=libs

all: dirs zlib bzip2 miniupnpc openssl speex speexdsp libxml curl sqlcipher ffmpeg rapidjson xapian jsonc botan asio copylibs
#rnp

download: \
	$(DOWNLOAD_PATH)/zlib-$(ZLIB_VERSION).tar.gz \
	$(DOWNLOAD_PATH)/bzip2-$(BZIP2_VERSION).tar.gz \
	$(DOWNLOAD_PATH)/miniupnpc-$(MINIUPNPC_VERSION).tar.gz \
	$(DOWNLOAD_PATH)/openssl-$(OPENSSL_VERSION).tar.gz \
	$(DOWNLOAD_PATH)/speex-$(SPEEX_VERSION).tar.gz \
	$(DOWNLOAD_PATH)/speexdsp-$(SPEEXDSP_VERSION).tar.gz \
	$(DOWNLOAD_PATH)/libxml2-$(LIBXML2_VERSION).tar.xz \
	$(DOWNLOAD_PATH)/libxslt-$(LIBXSLT_VERSION).tar.xz \
	$(DOWNLOAD_PATH)/curl-$(CURL_VERSION).tar.gz \
	$(DOWNLOAD_PATH)/tcl$(TCL_VERSION)-src.tar.gz \
	$(DOWNLOAD_PATH)/sqlcipher-$(SQLCIPHER_VERSION).tar.gz \
	$(DOWNLOAD_PATH)/ffmpeg-$(FFMPEG_VERSION).tar.xz \
	$(DOWNLOAD_PATH)/rapidjson-$(RAPIDJSON_VERSION).tar.gz \
	$(DOWNLOAD_PATH)/xapian-core-$(XAPIAN_VERSION).tar.xz

clean:
	rm -r -f $(BUILD_PATH)
	rm -r -f $(LIBS_PATH)

dirs:
	mkdir -p $(DOWNLOAD_PATH)
	mkdir -p $(BUILD_PATH)
	gcc --version | head --lines 1 | tr ' ' '\n' | tail -1 >$(BUILD_PATH)/gcc-version

$(DOWNLOAD_PATH)/zlib-$(ZLIB_VERSION).tar.gz:
	wget --no-check-certificate http://sourceforge.net/projects/libpng/files/zlib/$(ZLIB_VERSION)/zlib-$(ZLIB_VERSION).tar.gz/download -O $(DOWNLOAD_PATH)/zlib-$(ZLIB_VERSION).tar.gz

zlib: $(BUILD_PATH)/zlib-$(ZLIB_VERSION)

$(BUILD_PATH)/zlib-$(ZLIB_VERSION): $(DOWNLOAD_PATH)/zlib-$(ZLIB_VERSION).tar.gz
	# prepare
	rm -r -f $(BUILD_PATH)/zlib-*
	tar xvf $(DOWNLOAD_PATH)/zlib-$(ZLIB_VERSION).tar.gz
	# build
	cd zlib-$(ZLIB_VERSION) && make -j -f win32/Makefile.gcc libz.a
	# copy files
	mkdir -p $(BUILD_PATH)/zlib-$(ZLIB_VERSION).tmp/include
	cp zlib-$(ZLIB_VERSION)/zlib.h $(BUILD_PATH)/zlib-$(ZLIB_VERSION).tmp/include/
	cp zlib-$(ZLIB_VERSION)/zconf.h $(BUILD_PATH)/zlib-$(ZLIB_VERSION).tmp/include/
	mkdir -p $(BUILD_PATH)/zlib-$(ZLIB_VERSION).tmp/lib
	cp zlib-$(ZLIB_VERSION)/libz.a $(BUILD_PATH)/zlib-$(ZLIB_VERSION).tmp/lib/
	# cleanup
	rm -r -f zlib-$(ZLIB_VERSION)
	mv $(BUILD_PATH)/zlib-$(ZLIB_VERSION).tmp $(BUILD_PATH)/zlib-$(ZLIB_VERSION)

bzip2: $(BUILD_PATH)/bzip2-$(BZIP2_VERSION)

$(DOWNLOAD_PATH)/bzip2-$(BZIP2_VERSION).tar.gz:
	wget https://www.sourceware.org/pub/bzip2/bzip2-$(BZIP2_VERSION).tar.gz -O $(DOWNLOAD_PATH)/bzip2-$(BZIP2_VERSION).tar.gz

$(BUILD_PATH)/bzip2-$(BZIP2_VERSION): $(DOWNLOAD_PATH)/bzip2-$(BZIP2_VERSION).tar.gz
	# prepare
	rm -r -f $(BUILD_PATH)/bzip2-*
	tar xvf $(DOWNLOAD_PATH)/bzip2-$(BZIP2_VERSION).tar.gz
	# build
	#cd bzip2-$(BZIP2_VERSION) && make install PREFIX="`pwd`/../$(BUILD_PATH)"
	cd bzip2-$(BZIP2_VERSION) && make -j
	# copy files
	mkdir -p $(BUILD_PATH)/bzip2-$(BZIP2_VERSION).tmp/include
	cp bzip2-$(BZIP2_VERSION)/bzlib.h $(BUILD_PATH)/bzip2-$(BZIP2_VERSION).tmp/include/
	mkdir -p $(BUILD_PATH)/bzip2-$(BZIP2_VERSION).tmp/lib
	cp bzip2-$(BZIP2_VERSION)/libbz2.a $(BUILD_PATH)/bzip2-$(BZIP2_VERSION).tmp/lib/
	# cleanup
	rm -r -f bzip2-$(BZIP2_VERSION)
	mv $(BUILD_PATH)/bzip2-$(BZIP2_VERSION).tmp $(BUILD_PATH)/bzip2-$(BZIP2_VERSION)

miniupnpc: $(BUILD_PATH)/miniupnpc-$(MINIUPNPC_VERSION)

$(DOWNLOAD_PATH)/miniupnpc-$(MINIUPNPC_VERSION).tar.gz:
	wget http://miniupnp.free.fr/files/download.php?file=miniupnpc-$(MINIUPNPC_VERSION).tar.gz -O $(DOWNLOAD_PATH)/miniupnpc-$(MINIUPNPC_VERSION).tar.gz

$(BUILD_PATH)/miniupnpc-$(MINIUPNPC_VERSION): $(DOWNLOAD_PATH)/miniupnpc-$(MINIUPNPC_VERSION).tar.gz
	# prepare
	rm -r -f $(BUILD_PATH)/miniupnpc-*
	tar xvf $(DOWNLOAD_PATH)/miniupnpc-$(MINIUPNPC_VERSION).tar.gz
	# build
	cd miniupnpc-$(MINIUPNPC_VERSION) && export CC=gcc && export PATH=.:$$PATH && make -j -f Makefile.mingw libminiupnpc.a miniupnpc.dll
	# copy files
	mkdir -p $(BUILD_PATH)/miniupnpc-$(MINIUPNPC_VERSION).tmp/include/miniupnpc
	cp miniupnpc-$(MINIUPNPC_VERSION)/include/*.h $(BUILD_PATH)/miniupnpc-$(MINIUPNPC_VERSION).tmp/include/miniupnpc/
	mkdir -p $(BUILD_PATH)/miniupnpc-$(MINIUPNPC_VERSION).tmp/lib
	cp miniupnpc-$(MINIUPNPC_VERSION)/miniupnpc.lib $(BUILD_PATH)/miniupnpc-$(MINIUPNPC_VERSION).tmp/lib/
	mkdir -p $(BUILD_PATH)/miniupnpc-$(MINIUPNPC_VERSION).tmp/bin
	cp miniupnpc-$(MINIUPNPC_VERSION)/miniupnpc.dll $(BUILD_PATH)/miniupnpc-$(MINIUPNPC_VERSION).tmp/bin/
	# cleanup
	rm -r -f miniupnpc-$(MINIUPNPC_VERSION)
	mv $(BUILD_PATH)/miniupnpc-$(MINIUPNPC_VERSION).tmp $(BUILD_PATH)/miniupnpc-$(MINIUPNPC_VERSION)

openssl: $(BUILD_PATH)/openssl-$(OPENSSL_VERSION)

$(DOWNLOAD_PATH)/openssl-$(OPENSSL_VERSION).tar.gz:
	wget --no-check-certificate https://www.openssl.org/source/openssl-$(OPENSSL_VERSION).tar.gz -O $(DOWNLOAD_PATH)/openssl-$(OPENSSL_VERSION).tar.gz

$(BUILD_PATH)/openssl-$(OPENSSL_VERSION): $(DOWNLOAD_PATH)/openssl-$(OPENSSL_VERSION).tar.gz
	# prepare
	rm -r -f $(BUILD_PATH)/openssl-*
	tar xvf $(DOWNLOAD_PATH)/openssl-$(OPENSSL_VERSION).tar.gz
	# build
	#cd openssl-$(OPENSSL_VERSION) && ./config --prefix="`pwd`/../$(BUILD_PATH)"
	#cd openssl-$(OPENSSL_VERSION) && make install
	cd openssl-$(OPENSSL_VERSION) && ./config shared
	cd openssl-$(OPENSSL_VERSION) && make -j
	# copy files
	mkdir -p $(BUILD_PATH)/openssl-$(OPENSSL_VERSION).tmp/include/openssl
	cp openssl-$(OPENSSL_VERSION)/include/openssl/*.h $(BUILD_PATH)/openssl-$(OPENSSL_VERSION).tmp/include/openssl/
	mkdir -p $(BUILD_PATH)/openssl-$(OPENSSL_VERSION).tmp/bin
	if [ $(MSYSTEM) = "MINGW32" ] ; then cp openssl-$(OPENSSL_VERSION)/libcrypto-1_1.dll $(BUILD_PATH)/openssl-$(OPENSSL_VERSION).tmp/bin/ ; fi
	if [ $(MSYSTEM) = "MINGW32" ] ; then cp openssl-$(OPENSSL_VERSION)/libcrypto-1_1.dll $(BUILD_PATH)/openssl-$(OPENSSL_VERSION).tmp/bin/ ; fi
	if [ $(MSYSTEM) = "MINGW32" ] ; then cp openssl-$(OPENSSL_VERSION)/libssl-1_1.dll $(BUILD_PATH)/openssl-$(OPENSSL_VERSION).tmp/bin/ ; fi
	if [ $(MSYSTEM) = "MINGW64" ] ; then cp openssl-$(OPENSSL_VERSION)/libcrypto-1_1-x64.dll $(BUILD_PATH)/openssl-$(OPENSSL_VERSION).tmp/bin/ ; fi
	if [ $(MSYSTEM) = "MINGW64" ] ; then cp openssl-$(OPENSSL_VERSION)/libssl-1_1-x64.dll $(BUILD_PATH)/openssl-$(OPENSSL_VERSION).tmp/bin/ ; fi
	mkdir -p $(BUILD_PATH)/openssl-$(OPENSSL_VERSION).tmp/lib
	cp openssl-$(OPENSSL_VERSION)/libcrypto.dll.a $(BUILD_PATH)/openssl-$(OPENSSL_VERSION).tmp/lib/
	cp openssl-$(OPENSSL_VERSION)/libssl.dll.a $(BUILD_PATH)/openssl-$(OPENSSL_VERSION).tmp/lib/
	# cleanup
	rm -r -f openssl-$(OPENSSL_VERSION)
	mv $(BUILD_PATH)/openssl-$(OPENSSL_VERSION).tmp $(BUILD_PATH)/openssl-$(OPENSSL_VERSION)

speex: $(BUILD_PATH)/speex-$(SPEEX_VERSION)

$(DOWNLOAD_PATH)/speex-$(SPEEX_VERSION).tar.gz:
	wget --no-check-certificate http://downloads.xiph.org/releases/speex/speex-$(SPEEX_VERSION).tar.gz -O $(DOWNLOAD_PATH)/speex-$(SPEEX_VERSION).tar.gz

$(BUILD_PATH)/speex-$(SPEEX_VERSION): $(DOWNLOAD_PATH)/speex-$(SPEEX_VERSION).tar.gz
	# prepare
	rm -r -f $(BUILD_PATH)/speex-*
	tar xvf $(DOWNLOAD_PATH)/speex-$(SPEEX_VERSION).tar.gz
	# build
	cd speex-$(SPEEX_VERSION) && ./configure
	#cd speex-$(SPEEX_VERSION) && make install exec_prefix="`pwd`/../$(BUILD_PATH)"
	cd speex-$(SPEEX_VERSION) && make -j
	# copy files
	mkdir -p $(BUILD_PATH)/speex-$(SPEEX_VERSION).tmp/include/speex
	cp speex-$(SPEEX_VERSION)/include/speex/*.h $(BUILD_PATH)/speex-$(SPEEX_VERSION).tmp/include/speex/
	mkdir -p $(BUILD_PATH)/speex-$(SPEEX_VERSION).tmp/lib
	cp speex-$(SPEEX_VERSION)/libspeex/.libs/libspeex.a $(BUILD_PATH)/speex-$(SPEEX_VERSION).tmp/lib
	# cleanup
	rm -r -f speex-$(SPEEX_VERSION)
	mv $(BUILD_PATH)/speex-$(SPEEX_VERSION).tmp $(BUILD_PATH)/speex-$(SPEEX_VERSION)

speexdsp: $(BUILD_PATH)/speexdsp-$(SPEEXDSP_VERSION)

$(DOWNLOAD_PATH)/speexdsp-$(SPEEXDSP_VERSION).tar.gz:
	wget --no-check-certificate http://downloads.xiph.org/releases/speex/speexdsp-$(SPEEXDSP_VERSION).tar.gz -O $(DOWNLOAD_PATH)/speexdsp-$(SPEEXDSP_VERSION).tar.gz

$(BUILD_PATH)/speexdsp-$(SPEEXDSP_VERSION): $(DOWNLOAD_PATH)/speexdsp-$(SPEEXDSP_VERSION).tar.gz
	# prepare
	rm -r -f $(BUILD_PATH)/speexdsp-*
	tar xvf $(DOWNLOAD_PATH)/speexdsp-$(SPEEXDSP_VERSION).tar.gz
	# build
	cd speexdsp-$(SPEEXDSP_VERSION) && ./configure
	cd speexdsp-$(SPEEXDSP_VERSION) && make -j
	# copy files
	mkdir -p $(BUILD_PATH)/speexdsp-$(SPEEXDSP_VERSION).tmp/include/speex
	cp speexdsp-$(SPEEXDSP_VERSION)/include/speex/*.h $(BUILD_PATH)/speexdsp-$(SPEEXDSP_VERSION).tmp/include/speex/
	mkdir -p $(BUILD_PATH)/speexdsp-$(SPEEXDSP_VERSION).tmp/lib
	cp speexdsp-$(SPEEXDSP_VERSION)/libspeexdsp/.libs/libspeexdsp.a $(BUILD_PATH)/speexdsp-$(SPEEXDSP_VERSION).tmp/lib
	# cleanup
	rm -r -f speexdsp-$(SPEEXDSP_VERSION)
	mv $(BUILD_PATH)/speexdsp-$(SPEEXDSP_VERSION).tmp $(BUILD_PATH)/speexdsp-$(SPEEXDSP_VERSION)

libxml: \
	$(BUILD_PATH)/libxml2-$(LIBXML2_VERSION) \
	$(BUILD_PATH)/libxslt-$(LIBXSLT_VERSION)

$(DOWNLOAD_PATH)/libxml2-$(LIBXML2_VERSION).tar.xz:
	wget --no-check-certificate https://download.gnome.org/sources/libxml2/$(LIBXML2_MAIN_VERSION)/libxml2-$(LIBXML2_VERSION).tar.xz -O $(DOWNLOAD_PATH)/libxml2-$(LIBXML2_VERSION).tar.xz

$(DOWNLOAD_PATH)/libxslt-$(LIBXSLT_VERSION).tar.xz:
	wget --no-check-certificate https://download.gnome.org/sources/libxslt/$(LIBXSLT_MAIN_VERSION)/libxslt-$(LIBXSLT_VERSION).tar.xz -O $(DOWNLOAD_PATH)/libxslt-$(LIBXSLT_VERSION).tar.xz

$(BUILD_PATH)/libxml2-$(LIBXML2_VERSION) $(BUILD_PATH)/libxslt-$(LIBXSLT_VERSION): \
	$(DOWNLOAD_PATH)/libxml2-$(LIBXML2_VERSION).tar.xz \
	$(DOWNLOAD_PATH)/libxslt-$(LIBXSLT_VERSION).tar.xz
	# libxml2: prepare
	pacman --needed --noconfirm -S python3 pkg-config
	rm -r -f $(BUILD_PATH)/libxml2-*
	tar xvf $(DOWNLOAD_PATH)/libxml2-$(LIBXML2_VERSION).tar.xz
	# libxslt: prepare
	rm -r -f $(BUILD_PATH)/libxslt-*
	tar xvf $(DOWNLOAD_PATH)/libxml2-$(LIBXML2_VERSION).tar.xz
	tar xvf $(DOWNLOAD_PATH)/libxslt-$(LIBXSLT_VERSION).tar.xz
	# libxml2: build
	cd libxml2-$(LIBXML2_VERSION) && ./configure --without-iconv -enable-shared=no
	#cd libxml2-$(LIBXML2_VERSION) && make install exec_prefix="`pwd`/../$(BUILD_PATH)"
	cd libxml2-$(LIBXML2_VERSION) && make -j libxml2.la
	# libxslt: build
	cd libxslt-$(LIBXSLT_VERSION) && ./configure --with-libxml-src=../libxml2-$(LIBXML2_VERSION) -enable-shared=no CFLAGS=-DLIBXML_STATIC
	cd libxslt-$(LIBXSLT_VERSION)/libxslt && make -j
	cd libxslt-$(LIBXSLT_VERSION)/libexslt && make -j
	# libxml2: copy files
	mkdir -p $(BUILD_PATH)/libxml2-$(LIBXML2_VERSION).tmp/include/libxml
	cp libxml2-$(LIBXML2_VERSION)/include/libxml/*.h $(BUILD_PATH)/libxml2-$(LIBXML2_VERSION).tmp/include/libxml/
	mkdir -p $(BUILD_PATH)/libxml2-$(LIBXML2_VERSION).tmp/lib
	cp libxml2-$(LIBXML2_VERSION)/.libs/libxml2.a $(BUILD_PATH)/libxml2-$(LIBXML2_VERSION).tmp/lib/
	# libxslt: copy files
	mkdir -p $(BUILD_PATH)/libxslt-$(LIBXSLT_VERSION).tmp/include/libxslt
	cp libxslt-$(LIBXSLT_VERSION)/libxslt/*.h $(BUILD_PATH)/libxslt-$(LIBXSLT_VERSION).tmp/include/libxslt/
	mkdir -p $(BUILD_PATH)/libxslt-$(LIBXSLT_VERSION).tmp/lib
	cp libxslt-$(LIBXSLT_VERSION)/libxslt/.libs/libxslt.a $(BUILD_PATH)/libxslt-$(LIBXSLT_VERSION).tmp/lib/
	cp libxslt-$(LIBXSLT_VERSION)/libexslt/.libs/libexslt.a $(BUILD_PATH)/libxslt-$(LIBXSLT_VERSION).tmp/lib/
	# libxml2: cleanup
	rm -r -f libxml2-$(LIBXML2_VERSION)
	# libxslt: cleanup
	rm -r -f libxslt-$(LIBXSLT_VERSION)
	# finish
	mv $(BUILD_PATH)/libxml2-$(LIBXML2_VERSION).tmp $(BUILD_PATH)/libxml2-$(LIBXML2_VERSION)
	mv $(BUILD_PATH)/libxslt-$(LIBXSLT_VERSION).tmp $(BUILD_PATH)/libxslt-$(LIBXSLT_VERSION)

curl: $(BUILD_PATH)/curl-$(CURL_VERSION)

$(DOWNLOAD_PATH)/curl-$(CURL_VERSION).tar.gz:
	wget --no-check-certificate http://curl.haxx.se/download/curl-$(CURL_VERSION).tar.gz -O $(DOWNLOAD_PATH)/curl-$(CURL_VERSION).tar.gz

$(BUILD_PATH)/curl-$(CURL_VERSION): $(DOWNLOAD_PATH)/curl-$(CURL_VERSION).tar.gz
	# prepare
	rm -r -f $(BUILD_PATH)/curl-*
	tar xvf $(DOWNLOAD_PATH)/curl-$(CURL_VERSION).tar.gz
	# build
	cd curl-$(CURL_VERSION) && ./configure --disable-shared --with-ssl="`pwd`/../$(BUILD_PATH)/openssl-$(OPENSSL_VERSION)"
	#cd curl-$(CURL_VERSION) && make install exec_prefix="`pwd`/../$(BUILD_PATH)"
	cd curl-$(CURL_VERSION)/lib && make -j
	# copy files
	mkdir -p $(BUILD_PATH)/curl-$(CURL_VERSION).tmp/include/curl
	cp curl-$(CURL_VERSION)/include/curl/*.h $(BUILD_PATH)/curl-$(CURL_VERSION).tmp/include/curl/
	mkdir -p $(BUILD_PATH)/curl-$(CURL_VERSION).tmp/lib
	cp curl-$(CURL_VERSION)/lib/.libs/libcurl.a $(BUILD_PATH)/curl-$(CURL_VERSION).tmp/lib/
	# cleanup
	rm -r -f curl-$(CURL_VERSION)
	mv $(BUILD_PATH)/curl-$(CURL_VERSION).tmp $(BUILD_PATH)/curl-$(CURL_VERSION)

sqlcipher: $(BUILD_PATH)/sqlcipher-$(SQLCIPHER_VERSION)

$(DOWNLOAD_PATH)/tcl$(TCL_VERSION)-src.tar.gz:
	wget --no-check-certificate http://downloads.sourceforge.net/project/tcl/Tcl/$(TCL_VERSION)/tcl$(TCL_VERSION)-src.tar.gz -O $(DOWNLOAD_PATH)/tcl$(TCL_VERSION)-src.tar.gz

$(DOWNLOAD_PATH)/sqlcipher-$(SQLCIPHER_VERSION).tar.gz:
	wget --no-check-certificate https://github.com/sqlcipher/sqlcipher/archive/v$(SQLCIPHER_VERSION).tar.gz -O $(DOWNLOAD_PATH)/sqlcipher-$(SQLCIPHER_VERSION).tar.gz

$(BUILD_PATH)/sqlcipher-$(SQLCIPHER_VERSION): $(DOWNLOAD_PATH)/tcl$(TCL_VERSION)-src.tar.gz $(DOWNLOAD_PATH)/sqlcipher-$(SQLCIPHER_VERSION).tar.gz
	# prepare
	rm -r -f $(BUILD_PATH)/sqlcipher-*
	# tcl
	tar xvf $(DOWNLOAD_PATH)/tcl$(TCL_VERSION)-src.tar.gz
	mkdir -p tcl$(TCL_VERSION)/build
	cd tcl$(TCL_VERSION)/build && ../win/configure
	cd tcl$(TCL_VERSION)/build && make -j
	#sqlcipher
	tar xvf $(DOWNLOAD_PATH)/sqlcipher-$(SQLCIPHER_VERSION).tar.gz
	cd sqlcipher-$(SQLCIPHER_VERSION) && ln -s ../tcl$(TCL_VERSION)/build/tclsh86.exe tclsh
	mkdir -p tcl$(TCL_VERSION)/lib
	ln -s `pwd`/tcl$(TCL_VERSION)/library `pwd`/tcl$(TCL_VERSION)/lib/tcl8.6
	# build
	cd sqlcipher-$(SQLCIPHER_VERSION) && PATH=.:$$PATH:`pwd`/../tcl$(TCL_VERSION)/build && export LIBS="-L`pwd`/../$(BUILD_PATH)/openssl-$(OPENSSL_VERSION)/lib -lgdi32 $$LIBS" && ./configure --disable-shared --enable-static --enable-tempstore=yes CFLAGS="-DSQLITE_HAS_CODEC -I`pwd`/../$(BUILD_PATH)/openssl-$(OPENSSL_VERSION)/include -I`pwd`/../tcl$(TCL_VERSION)/generic" LDFLAGS="-L`pwd`/../$(BUILD_PATH)/openssl-$(OPENSSL_VERSION)/lib -lcrypto -lgdi32" --with-tcl="`pwd`/../tcl$(TCL_VERSION)/build" && make -j install prefix="`pwd`/install"
	# copy files
	mkdir -p $(BUILD_PATH)/sqlcipher-$(SQLCIPHER_VERSION).tmp/include
	cp -r sqlcipher-$(SQLCIPHER_VERSION)/install/include/* $(BUILD_PATH)/sqlcipher-$(SQLCIPHER_VERSION).tmp/include/
	mkdir -p $(BUILD_PATH)/sqlcipher-$(SQLCIPHER_VERSION).tmp/lib
	cp sqlcipher-$(SQLCIPHER_VERSION)/install/lib/libsqlcipher.a $(BUILD_PATH)/sqlcipher-$(SQLCIPHER_VERSION).tmp/lib/
	mkdir -p $(BUILD_PATH)/sqlcipher-$(SQLCIPHER_VERSION).tmp/bin
	cp sqlcipher-$(SQLCIPHER_VERSION)/install/bin/sqlcipher.exe $(BUILD_PATH)/sqlcipher-$(SQLCIPHER_VERSION).tmp/bin/
	# cleanup
	rm -r -f sqlcipher-$(SQLCIPHER_VERSION)
	rm -r -f tcl$(TCL_VERSION)
	mv $(BUILD_PATH)/sqlcipher-$(SQLCIPHER_VERSION).tmp $(BUILD_PATH)/sqlcipher-$(SQLCIPHER_VERSION)

ffmpeg: $(BUILD_PATH)/ffmpeg-$(FFMPEG_VERSION)

$(DOWNLOAD_PATH)/ffmpeg-$(FFMPEG_VERSION).tar.xz:
	wget --no-check-certificate https://ffmpeg.org/releases/ffmpeg-$(FFMPEG_VERSION).tar.xz -O $(DOWNLOAD_PATH)/ffmpeg-$(FFMPEG_VERSION).tar.xz

$(BUILD_PATH)/ffmpeg-$(FFMPEG_VERSION): $(DOWNLOAD_PATH)/ffmpeg-$(FFMPEG_VERSION).tar.xz
	# prepare
	rm -r -f $(BUILD_PATH)/ffmpeg-*
	tar xvf $(DOWNLOAD_PATH)/ffmpeg-$(FFMPEG_VERSION).tar.xz
	# build
	cd ffmpeg-$(FFMPEG_VERSION) && ./configure --disable-shared --enable-static --disable-programs --disable-ffmpeg --disable-ffplay --disable-ffprobe --disable-doc --disable-htmlpages --disable-manpages --disable-podpages --disable-txtpages --disable-yasm --disable-everything --enable-encoder=mpeg4 --enable-decoder=mpeg4 --prefix="`pwd`/../$(BUILD_PATH)/ffmpeg-$(FFMPEG_VERSION).tmp"
	cd ffmpeg-$(FFMPEG_VERSION) && make -j install
	# cleanup
	rm -r -f ffmpeg-$(FFMPEG_VERSION)
	mv $(BUILD_PATH)/ffmpeg-$(FFMPEG_VERSION).tmp $(BUILD_PATH)/ffmpeg-$(FFMPEG_VERSION)

rapidjson: $(BUILD_PATH)/rapidjson-$(RAPIDJSON_VERSION)

$(DOWNLOAD_PATH)/rapidjson-$(RAPIDJSON_VERSION).tar.gz:
	wget --no-check-certificate https://github.com/Tencent/rapidjson/archive/v$(RAPIDJSON_VERSION).tar.gz -O $(DOWNLOAD_PATH)/rapidjson-$(RAPIDJSON_VERSION).tar.gz

$(BUILD_PATH)/rapidjson-$(RAPIDJSON_VERSION): $(DOWNLOAD_PATH)/rapidjson-$(RAPIDJSON_VERSION).tar.gz
	# prepare
	rm -r -f $(BUILD_PATH)/rapidjson-*
	tar xvf $(DOWNLOAD_PATH)/rapidjson-$(RAPIDJSON_VERSION).tar.gz
	# build
	#mkdir -p rapidjson-$(RAPIDJSON_VERSION)/build
	#cd rapidjson-$(RAPIDJSON_VERSION)/build && cmake .. -G"MSYS Makefiles"
	#cd rapidjson-$(RAPIDJSON_VERSION)/build && make
	# copy files
	mkdir -p $(BUILD_PATH)/rapidjson-$(RAPIDJSON_VERSION).tmp/include
	cp -r rapidjson-$(RAPIDJSON_VERSION)/include/* $(BUILD_PATH)/rapidjson-$(RAPIDJSON_VERSION).tmp/include/
	# cleanup
	rm -r -f rapidjson-$(RAPIDJSON_VERSION)
	mv $(BUILD_PATH)/rapidjson-$(RAPIDJSON_VERSION).tmp $(BUILD_PATH)/rapidjson-$(RAPIDJSON_VERSION)

xapian: $(BUILD_PATH)/xapian-core-$(XAPIAN_VERSION)

$(DOWNLOAD_PATH)/xapian-core-$(XAPIAN_VERSION).tar.xz:
	wget --no-check-certificate https://oligarchy.co.uk/xapian/$(XAPIAN_VERSION)/xapian-core-$(XAPIAN_VERSION).tar.xz -O $(DOWNLOAD_PATH)/xapian-core-$(XAPIAN_VERSION).tar.xz

$(BUILD_PATH)/xapian-core-$(XAPIAN_VERSION): $(DOWNLOAD_PATH)/xapian-core-$(XAPIAN_VERSION).tar.xz
	# prepare
	rm -r -f $(BUILD_PATH)/xapian-core-*
	tar xvf $(DOWNLOAD_PATH)/xapian-core-$(XAPIAN_VERSION).tar.xz
	# build
	#cd xapian-core-$(XAPIAN_VERSION) && ./configure --disable-shared --enable-static --prefix="`pwd`/../$(BUILD_PATH)/xapian-core-$(XAPIAN_VERSION).tmp"
	#cd xapian-core-$(XAPIAN_VERSION) && make install
	cd xapian-core-$(XAPIAN_VERSION) && ./configure --disable-shared --enable-static
	cd xapian-core-$(XAPIAN_VERSION) && make -j
	# copy files
	mkdir -p $(BUILD_PATH)/xapian-core-$(XAPIAN_VERSION).tmp/include
	cp -r xapian-core-$(XAPIAN_VERSION)/include/* $(BUILD_PATH)/xapian-core-$(XAPIAN_VERSION).tmp/include/
	rm $(BUILD_PATH)/xapian-core-$(XAPIAN_VERSION).tmp/include/Makefile*
	mkdir -p $(BUILD_PATH)/xapian-core-$(XAPIAN_VERSION).tmp/lib
	cp -r xapian-core-$(XAPIAN_VERSION)/.libs/libxapian.a $(BUILD_PATH)/xapian-core-$(XAPIAN_VERSION).tmp/lib/
	# cleanup
	rm -r -f xapian-core-$(XAPIAN_VERSION)
	mv $(BUILD_PATH)/xapian-core-$(XAPIAN_VERSION).tmp $(BUILD_PATH)/xapian-core-$(XAPIAN_VERSION)

jsonc: $(BUILD_PATH)/json-c-$(JSON_C_VERSION)

$(BUILD_PATH)/json-c-$(JSON_C_VERSION):
	# prepare
	rm -r -f $(BUILD_PATH)/json-c-*
	[ -d "json-c-$(JSON_C_VERSION)" ] || git clone https://github.com/json-c/json-c.git --depth=1 --branch json-c-$(JSON_C_VERSION) "json-c-$(JSON_C_VERSION)"
	# build
	mkdir -p json-c-$(JSON_C_VERSION)/build
	cd json-c-$(JSON_C_VERSION)/build && cmake .. -G"MSYS Makefiles" -Wno-dev -DCMAKE_BUILD_TYPE="release" -DBUILD_SHARED_LIBS=off -DBUILD_STATIC_LIBS=on -DBUILD_TESTING=off -DCMAKE_CXX_FLAGS="-D__MINGW_USE_VC2005_COMPAT" -DCMAKE_INSTALL_PREFIX="`pwd`/install" -DCMAKE_INSTALL_PREFIX="`pwd`/../../$(BUILD_PATH)/json-c-$(JSON_C_VERSION).tmp"
	cd json-c-$(JSON_C_VERSION)/build && make -j install
	# cleanup
	rm -r -f json-c-$(JSON_C_VERSION)
	mv $(BUILD_PATH)/json-c-$(JSON_C_VERSION).tmp $(BUILD_PATH)/json-c-$(JSON_C_VERSION)

botan: $(BUILD_PATH)/botan-$(BOTAN_VERSION)

$(BUILD_PATH)/botan-$(BOTAN_VERSION):
	# prepare
	pacman --needed --noconfirm -S python3
	rm -r -f $(BUILD_PATH)/botan-*
	[ -d "botan-$(BOTAN_VERSION)" ] || git clone https://github.com/randombit/botan.git --depth=1 --branch $(BOTAN_VERSION) "botan-$(BOTAN_VERSION)"
	# build
	if [ $(MSYSTEM) = "MINGW32" ] ; then cd botan-$(BOTAN_VERSION) && ./configure.py --os=mingw --cpu=x86_32 --disable-shared-library --enable-static-library --extra-cxxflags="-D__MINGW_USE_VC2005_COMPAT" --prefix="`pwd`/../$(BUILD_PATH)/botan-$(BOTAN_VERSION).tmp" ; fi
	if [ $(MSYSTEM) = "MINGW64" ] ; then cd botan-$(BOTAN_VERSION) && ./configure.py --os=mingw --cpu=x86_64 --disable-shared-library --enable-static-library --prefix="`pwd`/../$(BUILD_PATH)/botan-$(BOTAN_VERSION).tmp" ; fi
	cd botan-$(BOTAN_VERSION) && make -j install
	# cleanup
	rm -r -f botan-$(BOTAN_VERSION)
	mv $(BUILD_PATH)/botan-$(BOTAN_VERSION).tmp $(BUILD_PATH)/botan-$(BOTAN_VERSION)

asio: $(BUILD_PATH)/asio-$(ASIO_VERSION)

$(BUILD_PATH)/asio-$(ASIO_VERSION):
	# prepare
	rm -r -f $(BUILD_PATH)/asio-*
	[ -d "asio-$(ASIO_VERSION)" ] || git clone https://github.com/chriskohlhoff/asio.git --depth=1 --branch asio-$(ASIO_VERSION) "asio-$(ASIO_VERSION)"
	# copy files
	mkdir -p $(BUILD_PATH)/asio-$(ASIO_VERSION).tmp/include/asio
	cp asio-$(ASIO_VERSION)/asio/include/*.hpp $(BUILD_PATH)/asio-$(ASIO_VERSION).tmp/include/
	cp -r asio-$(ASIO_VERSION)/asio/include/asio/* $(BUILD_PATH)/asio-$(ASIO_VERSION).tmp/include/asio/
	# cleanup
	rm -r -f asio-$(ASIO_VERSION)
	mv $(BUILD_PATH)/asio-$(ASIO_VERSION).tmp $(BUILD_PATH)/asio-$(ASIO_VERSION)

rnp: $(BUILD_PATH)/rnp-$(RNP_VERSION)

$(BUILD_PATH)/rnp-$(RNP_VERSION):
	# prepare
	rm -r -f $(BUILD_PATH)/rnp-*
	[ -d "rnp-$(RNP_VERSION)" ] || git clone https://github.com/rnpgp/rnp.git --depth=1 --branch v$(RNP_VERSION) --recurse-submodules --shallow-submodules "rnp-$(RNP_VERSION)"
	# build
	mkdir -p rnp-$(RNP_VERSION)/build
	cd rnp-$(RNP_VERSION)/build && cmake .. -G"MSYS Makefiles" -Wno-dev -DCMAKE_INSTALL_PREFIX="`pwd`/install" -DBUILD_SHARED_LIBS=yes -DBUILD_TESTING=off -DCMAKE_CXX_FLAGS="-D__MINGW_USE_VC2005_COMPAT -D__STDC_FORMAT_MACROS" -DBZIP2_INCLUDE_DIR="`pwd`/../../$(BUILD_PATH)/bzip2-$(BZIP2_VERSION)/include" -DBZIP2_LIBRARY_RELEASE="`pwd`/../../$(BUILD_PATH)/bzip2-$(BZIP2_VERSION)/lib/libbz2.a" -DBZIP2_LIBRARIES="`pwd`/../../$(BUILD_PATH)/bzip2-$(BZIP2_VERSION)/lib/libbz2.a" -DZLIB_INCLUDE_DIR="`pwd`/../../$(BUILD_PATH)/zlib-$(ZLIB_VERSION)/include" -DZLIB_LIBRARY="`pwd`/../../$(BUILD_PATH)/zlib-$(ZLIB_VERSION)/lib/libz.a" -DJSON-C_INCLUDE_DIR="`pwd`/../../$(BUILD_PATH)/json-c-$(JSON_C_VERSION)/include/json-c" -DJSON-C_LIBRARY="`pwd`/../../$(BUILD_PATH)/json-c-$(JSON_C_VERSION)/lib/libjson-c.a" -DBOTAN_INCLUDE_DIR="`pwd`/../../$(BUILD_PATH)/botan-$(BOTAN_VERSION)/include/botan-`echo $(BOTAN_VERSION) | cut -c1-1`" -DBOTAN_LIBRARY="`pwd`/../../$(BUILD_PATH)/botan-$(BOTAN_VERSION)/lib/libbotan-`echo $(BOTAN_VERSION) | cut -c1-1`.a"
	cmake --build rnp-$(RNP_VERSION)/build
	# copy files
	mkdir -p $(BUILD_PATH)/rnp-$(RNP_VERSION).tmp/include/rnp
	cp -r rnp-$(RNP_VERSION)/include/rnp/* $(BUILD_PATH)/rnp-$(RNP_VERSION).tmp/include/rnp/
	cp -r rnp-$(RNP_VERSION)/build/src/lib/rnp/* $(BUILD_PATH)/rnp-$(RNP_VERSION).tmp/include/rnp/
	mkdir -p $(BUILD_PATH)/rnp-$(RNP_VERSION).tmp/lib
	cp -r rnp-$(RNP_VERSION)/build/src/lib/librnp.dll.a $(BUILD_PATH)/rnp-$(RNP_VERSION).tmp/lib/
	mkdir -p $(BUILD_PATH)/rnp-$(RNP_VERSION).tmp/bin
	cp -r rnp-$(RNP_VERSION)/build/src/lib/librnp.dll $(BUILD_PATH)/rnp-$(RNP_VERSION).tmp/bin/
	# cleanup
	rm -r -f rnp-$(RNP_VERSION)
	mv $(BUILD_PATH)/rnp-$(RNP_VERSION).tmp $(BUILD_PATH)/rnp-$(RNP_VERSION)

copylibs:
	rm -r -f $(LIBS_PATH) ; \
	mkdir -p $(LIBS_PATH) ; \
	cp -p $(BUILD_PATH)/gcc-version $(LIBS_PATH) ; \
	find $(BUILD_PATH) -mindepth 1 -maxdepth 1 -type d -not -name "*.tmp" -print -exec cp -r -p {}/. $(LIBS_PATH) \; ; \
