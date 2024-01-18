arch ?= x86_64
kernel := build/kernel-$(arch).bin
img := build/os-$(arch).img

linker_script := src/arch/$(arch)/linker.ld
grub_cfg := src/arch/$(arch)/grub.cfg
assembly_source_files := $(wildcard src/arch/$(arch)/*.asm)
assembly_object_files := $(patsubst src/arch/$(arch)/%.asm, \
	build/arch/$(arch)/%.o, $(assembly_source_files))

.PHONY: all clean run img

all: $(kernel)

clean:
	@rm -r build

run: $(img)
	@qemu-system-x86_64 -drive file=foo.img,format=raw

img: $(img)

$(img): $(kernel) $(grub_cfg)
	mkdir -p build/.img/boot/grub ; \
	cp $(kernel) build/.img/boot/kernel.bin ; \
	cp $(grub_cfg) build/.img/boot/grub ; \
	dd if=/dev/zero of=foo.img bs=512 count=32768 ; \
	parted foo.img mklabel msdos ; \
	parted foo.img mkpart primary fat32 2048s 30720s ; \
	parted foo.img set 1 boot on ; \
	loop0=$$(losetup -f) ; \
	sudo losetup $$loop0 foo.img ; \
	loop1=$$(losetup -f) ; \
	sudo losetup $$loop1 foo.img -o 1048576 ; \
	sudo mkdosfs -F32 -f 2 $$loop1 ; \
	sudo mount $$loop1 /mnt/fatgrub ; \
	sudo grub-install -d /home/cpe454/opt/cross/lib/grub/i386-pc --root-directory=/mnt/fatgrub --no-floppy --modules="normal part_msdos ext2 multiboot" $$loop0 ; \
	sudo cp -r build/.img/* /mnt/fatgrub ; \
	sudo umount /mnt/fatgrub ; \
	sudo losetup -d $$loop0 ; \
	sudo losetup -d $$loop1


$(kernel): $(assembly_object_files) $(linker_script)
	@x86_64-elf-ld -n -T $(linker_script) -o $(kernel) $(assembly_object_files)

# compile assembly files
build/arch/$(arch)/%.o: src/arch/$(arch)/%.asm
	@mkdir -p $(shell dirname $@)
	@nasm -felf64 $< -o $@
