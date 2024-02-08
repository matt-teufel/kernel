#include <stdint-gcc.h>

#define PIC1		0x20		/* IO base address for master PIC */
#define PIC2		0xA0		/* IO base address for slave PIC */
#define PIC1_COMMAND	PIC1
#define PIC1_DATA	(PIC1+1)
#define PIC2_COMMAND	PIC2
#define PIC2_DATA	(PIC2+1)

#define IDT_SIZE 256

#define STI()  asm volatile ("sti" ::: "memory")
#define CLI() asm volatile ("cli" ::: "memory")

static inline void io_wait(void);
static inline uint8_t inb(uint16_t port);
static inline void outb(uint16_t port, uint8_t val);
void PIC_remap(int offset1, int offset2);

extern void IRQ_init(void);
extern void IRQ_set_mask(int irq);
extern void IRQ_clear_mask(int irq);
extern int IRQ_get_mask(int IRQline);
extern void IRQ_end_of_interrupt(int irq);

typedef void (*irq_handler_t)(int, int, void*);
extern void IRQ_set_handler(int irq, irq_handler_t handler, void *arg);

struct IDT_entry { 
    uint16_t target_offset_lower;
    uint16_t target_selector;
    uint8_t reserved2:5;
    uint8_t IST:3;
    uint8_t P:1;
    uint8_t DPL:2;
    uint8_t zero:1;
    uint8_t type:4;
    uint16_t target_offset_middle;
    uint32_t target_offset_upper;
    uint32_t reserved1;
} __attribute__((packed));

struct IDT_descriptor{ 
    uint16_t limit;
    uint64_t base;
} __attribute__((packed));

struct IRQ_entry { 
    irq_handler_t handler;
}

#define TO_MASK_UPPER_SHIFT
#define TO_MASK_MIDDLE ()

#define GDT_OFFSET 8
#define TRAP_GATE 0xF
#define INT_GATE 0xE

#define DF 8
#define TS 10
#define NP 11
#define STE 12 
#define GP 13
#define PF 14


void init_IRQ_entries();
void loadIDT();
void set_IDT_entry(int idx, uintptr_t entryPoint);


extern void irq_entry_0();
extern void irq_entry_1();
extern void irq_entry_2();
extern void irq_entry_3();
extern void irq_entry_4();
extern void irq_entry_5();
extern void irq_entry_6();
extern void irq_entry_7();
extern void irq_entry_8();
extern void irq_entry_9();
extern void irq_entry_10();
extern void irq_entry_11();
extern void irq_entry_12();
extern void irq_entry_13();
extern void irq_entry_14();
extern void irq_entry_15();
extern void irq_entry_16();
extern void irq_entry_17();
extern void irq_entry_18();
extern void irq_entry_19();
extern void irq_entry_20();
extern void irq_entry_21();
extern void irq_entry_22();
extern void irq_entry_23();
extern void irq_entry_24();
extern void irq_entry_25();
extern void irq_entry_26();
extern void irq_entry_27();
extern void irq_entry_28();
extern void irq_entry_29();
extern void irq_entry_30();
extern void irq_entry_31();
extern void irq_entry_32();
extern void irq_entry_33();
extern void irq_entry_34();
extern void irq_entry_35();
extern void irq_entry_36();
extern void irq_entry_37();
extern void irq_entry_38();
extern void irq_entry_39();
extern void irq_entry_40();
extern void irq_entry_41();
extern void irq_entry_42();
extern void irq_entry_43();
extern void irq_entry_44();
extern void irq_entry_45();
extern void irq_entry_46();
extern void irq_entry_47();
extern void irq_entry_48();
extern void irq_entry_49();
extern void irq_entry_50();
extern void irq_entry_51();
extern void irq_entry_52();
extern void irq_entry_53();
extern void irq_entry_54();
extern void irq_entry_55();
extern void irq_entry_56();
extern void irq_entry_57();
extern void irq_entry_58();
extern void irq_entry_59();
extern void irq_entry_60();
extern void irq_entry_61();
extern void irq_entry_62();
extern void irq_entry_63();
extern void irq_entry_64();
extern void irq_entry_65();
extern void irq_entry_66();
extern void irq_entry_67();
extern void irq_entry_68();
extern void irq_entry_69();
extern void irq_entry_70();
extern void irq_entry_71();
extern void irq_entry_72();
extern void irq_entry_73();
extern void irq_entry_74();
extern void irq_entry_75();
extern void irq_entry_76();
extern void irq_entry_77();
extern void irq_entry_78();
extern void irq_entry_79();
extern void irq_entry_80();
extern void irq_entry_81();
extern void irq_entry_82();
extern void irq_entry_83();
extern void irq_entry_84();
extern void irq_entry_85();
extern void irq_entry_86();
extern void irq_entry_87();
extern void irq_entry_88();
extern void irq_entry_89();
extern void irq_entry_90();
extern void irq_entry_91();
extern void irq_entry_92();
extern void irq_entry_93();
extern void irq_entry_94();
extern void irq_entry_95();
extern void irq_entry_96();
extern void irq_entry_97();
extern void irq_entry_98();
extern void irq_entry_99();
extern void irq_entry_100();
extern void irq_entry_101();
extern void irq_entry_102();
extern void irq_entry_103();
extern void irq_entry_104();
extern void irq_entry_105();
extern void irq_entry_106();
extern void irq_entry_107();
extern void irq_entry_108();
extern void irq_entry_109();
extern void irq_entry_110();
extern void irq_entry_111();
extern void irq_entry_112();
extern void irq_entry_113();
extern void irq_entry_114();
extern void irq_entry_115();
extern void irq_entry_116();
extern void irq_entry_117();
extern void irq_entry_118();
extern void irq_entry_119();
extern void irq_entry_120();
extern void irq_entry_121();
extern void irq_entry_122();
extern void irq_entry_123();
extern void irq_entry_124();
extern void irq_entry_125();
extern void irq_entry_126();
extern void irq_entry_127();
extern void irq_entry_128();
extern void irq_entry_129();
extern void irq_entry_130();
extern void irq_entry_131();
extern void irq_entry_132();
extern void irq_entry_133();
extern void irq_entry_134();
extern void irq_entry_135();
extern void irq_entry_136();
extern void irq_entry_137();
extern void irq_entry_138();
extern void irq_entry_139();
extern void irq_entry_140();
extern void irq_entry_141();
extern void irq_entry_142();
extern void irq_entry_143();
extern void irq_entry_144();
extern void irq_entry_145();
extern void irq_entry_146();
extern void irq_entry_147();
extern void irq_entry_148();
extern void irq_entry_149();
extern void irq_entry_150();
extern void irq_entry_151();
extern void irq_entry_152();
extern void irq_entry_153();
extern void irq_entry_154();
extern void irq_entry_155();
extern void irq_entry_156();
extern void irq_entry_157();
extern void irq_entry_158();
extern void irq_entry_159();
extern void irq_entry_160();
extern void irq_entry_161();
extern void irq_entry_162();
extern void irq_entry_163();
extern void irq_entry_164();
extern void irq_entry_165();
extern void irq_entry_166();
extern void irq_entry_167();
extern void irq_entry_168();
extern void irq_entry_169();
extern void irq_entry_170();
extern void irq_entry_171();
extern void irq_entry_172();
extern void irq_entry_173();
extern void irq_entry_174();
extern void irq_entry_175();
extern void irq_entry_176();
extern void irq_entry_177();
extern void irq_entry_178();
extern void irq_entry_179();
extern void irq_entry_180();
extern void irq_entry_181();
extern void irq_entry_182();
extern void irq_entry_183();
extern void irq_entry_184();
extern void irq_entry_185();
extern void irq_entry_186();
extern void irq_entry_187();
extern void irq_entry_188();
extern void irq_entry_189();
extern void irq_entry_190();
extern void irq_entry_191();
extern void irq_entry_192();
extern void irq_entry_193();
extern void irq_entry_194();
extern void irq_entry_195();
extern void irq_entry_196();
extern void irq_entry_197();
extern void irq_entry_198();
extern void irq_entry_199();
extern void irq_entry_200();
extern void irq_entry_201();
extern void irq_entry_202();
extern void irq_entry_203();
extern void irq_entry_204();
extern void irq_entry_205();
extern void irq_entry_206();
extern void irq_entry_207();
extern void irq_entry_208();
extern void irq_entry_209();
extern void irq_entry_210();
extern void irq_entry_211();
extern void irq_entry_212();
extern void irq_entry_213();
extern void irq_entry_214();
extern void irq_entry_215();
extern void irq_entry_216();
extern void irq_entry_217();
extern void irq_entry_218();
extern void irq_entry_219();
extern void irq_entry_220();
extern void irq_entry_221();
extern void irq_entry_222();
extern void irq_entry_223();
extern void irq_entry_224();
extern void irq_entry_225();
extern void irq_entry_226();
extern void irq_entry_227();
extern void irq_entry_228();
extern void irq_entry_229();
extern void irq_entry_230();
extern void irq_entry_231();
extern void irq_entry_232();
extern void irq_entry_233();
extern void irq_entry_234();
extern void irq_entry_235();
extern void irq_entry_236();
extern void irq_entry_237();
extern void irq_entry_238();
extern void irq_entry_239();
extern void irq_entry_240();
extern void irq_entry_241();
extern void irq_entry_242();
extern void irq_entry_243();
extern void irq_entry_244();
extern void irq_entry_245();
extern void irq_entry_246();
extern void irq_entry_247();
extern void irq_entry_248();
extern void irq_entry_249();
extern void irq_entry_250();
extern void irq_entry_251();
extern void irq_entry_252();
extern void irq_entry_253();
extern void irq_entry_254();
extern void irq_entry_255();

