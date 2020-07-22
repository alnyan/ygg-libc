# Files
HEADERS=$(shell find include -type f -name "*.h")
INSTALL_HEADERS=$(filter-out include/_libc/%,$(HEADERS))
OBJ_CRT=$(O)/obj/crt0.o
SRC_LIBC=$(shell find src -type f -name "*.c")
AS_SRC_LIBC=$(shell find src -type f -name "*.S")
OBJ_LIBC=$(SRC_LIBC:src/%.c=$(O)/libc/%.o) $(AS_SRC_LIBC:src/%.S=$(O)/libc/%.o)
SRC_DIR_LIBC=$(shell find src/* -type d)
DIR_LIBC=$(SRC_DIR_LIBC:src/%=$(O)/libc/%)
STATIC_LIBS=$(O)/lib/libc.a
SHARED_LIBS=

# Build
CFLAGS=-I include \
	   -ffreestanding \
	   -Wall \
	   -Wextra \
	   -Werror \
	   -zmax-page-size=4096
LDFLAGS=-nostdlib
CC=$(CROSS_COMPILE)gcc

O=build
DESTDIR?=/usr/local
LIBS=$(STATIC_LIBS) $(SHARED_LIBS)

### General rules

all: mkdirs $(LIBS) $(OBJ_CRT)

mkdirs:
	mkdir -p $(O)/obj $(O)/lib $(DIR_LIBC)

clean:
	rm -rf $(O)

### Install rules

install-crt: mkdirs $(OBJ_CRT)
	$(foreach obj,$(OBJ_CRT), \
		install -Dm 0644 $(obj) $(obj:$(O)/obj/%.o=$(DESTDIR)/lib/%.o); \
	)

install-static-libs: mkdirs $(STATIC_LIBS)
	$(foreach lib,$(STATIC_LIBS), \
		install -Dm 0644 $(lib) $(DESTDIR)/$(lib:$(O)/%=%); \
	)

install-headers: mkdirs $(INSTALL_HEADERS)
	$(foreach hdr,$(INSTALL_HEADERS), \
		install -Dm 0644 $(hdr) $(DESTDIR)/$(hdr:$(O)/%=%); \
	)

install: install-crt install-static-libs install-headers

### CRT objects

$(O)/obj/crt%.o: crt/crt%.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

### lib

$(O)/lib/libc.a: $(OBJ_LIBC)
	@$(CROSS_COMPILE)ar rcs $@
	@$(foreach obj,$(OBJ_LIBC), \
		$(CROSS_COMPILE)ar rs $@ $(obj); \
	)

$(O)/libc/%.o: src/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(O)/libc/%.o: src/%.S $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<
