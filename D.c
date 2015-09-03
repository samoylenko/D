#define NULL 0
#define abs(x) (x<0?-x:x)
#define n    15
#define pi   3.1415926536
#define a1xy pi/800
#define xc   320/2
#define yc   200/2

typedef unsigned int word;
typedef unsigned char byte;

void *scr, *scr1, *txtbuf;
byte curline=0;
word curpos=0, dssav=0;

char text[] = "КОМИК ТРУППА!";
char greetz1[] = "ПРИВЕТЫ:";
char greetz[] =
{
  "ДИМКЕ КАHДАУРОВУ    " \
  "СЕРЕГЕ ПАHКОВУ      " \
  "СЕРЕГЕ ВЕДИЩЕВУ     " \
  "ИЛЮХЕ КОHHОВУ       " \
  "АHДРЮХЕ КОЛОТИЛИHУ  " \
  "ДЕHЕ ЯЦУТКО         " \
  "ЮРКЕ СЕГИДЕ         " \
  "HИКУ СЛИПЧЕHКО      " \
  "АHТОХЕ ТРОФИМОВУ    " \
  "КОЛЕ БУХАЛОВУ       " \
  "ЛЕХЕ МИХНЕНКО       " \
  "ЖЕHЬКЕ ФЕДОТОВУ     " \
  "MИХЕ КЛЕУЗОВИЧУ     " \
  "HАСТЮХЕ(KIKI)       " \
  "ВАHЬКУ ШИРЯЕВУ      " \
  "МИХЕ КОВАЛЕВУ       " \
  "ЮРИКУ АВТОМОНОВУ    " \
  "ИHГАЧКЕ ТКАЧЕВОЙ    " \
  "АHДРЮХЕ ИВЛЕВУ      " \
  "ДИМКЕ HАСОHОВУ      " \
  "ВОВЦУ ЛИТВИHЕHКО    " \
  "СОКРАТУ СТОФОРАHДОВУ" \
  "ЮЛЕHЬКЕ ГУЗАHОВОЙ   " \
  "ПАШЕ СЫТHИКОВУ      " \
  "ТЕМКЕ ЯHКОВУ        " \
  "ЮРКЕ ЖИГАЙЛО        " \
  "ЛЕХЕ КОРHИЕHКО      " \
  "КОСТИКУ ТКАЛИЧ      " \
  "ВИТАЛИКУ ГАЛУШКО    " \
  "МАКСУ ХАПОВУ        " \
  "ЛЕHОЧКЕ МОРОЗОВОЙ   " \
  "ЯЖЭHЯМОСКВИТИHУ ;)  " \
  "ТЕМКЕ ПРОХОРОВУ     " \
  "ЧЕРHЫШ ВОВАHУ       " \
  "ТРУХАHОВУ ДИМКЕ     " \
  "КОЛЯHУ КАРHАУХУ     " \
  "ОЗЕРОВУ РОМКЕ       " \
  "ЖЕHЬКЕ ДЕМЕHЮКУ     " \
  "ЛЕХЕ ФОРСИКОВУ      " \
  "АHДЕРФАЙТУ          " \
  "                    "
};

char maintext[] =
{
  "ESC - ВЫХОД,Б**!" \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  " ХE-ХE,ЭТО,ТИПА," \
  "  ***** ТАКАЯ   " \
  "   ДЕРГАЕТСЯ.   " \
  "                " \
  "  *****,**** НА " \
  "166MHZ ДЕРГАЕТСЯ" \
  " КАК НАДО, А НА " \
  "150 - ТОРМОЗИЦА." \
  "                " \
  " НУ,КОРОЧЕ,ЭТО  " \
  "ВСЕ - *****,КОГО" \
  "ОНО ВАПЩЕ ****? " \
  "                " \
  "  ГЛАВНОЕ,ЧТО   " \
  " РАБОТАЕТ.МЫ ЖЕ " \
  "ТЕПЕРЬ ПИСИШНИКИ" \
  "И НАМ ******* НА" \
  " КРАСОТУ КОДА И " \
  "  СКОРОСТЬ ЕГО  " \
  "   ВЫПОЛНЕНИЯ.  " \
  "                " \
  "И ВАПЩЕ ЭТО НАША" \
  "ПЕРВАЯ РАБОТА НА" \
  " ЯЗЫКЕ ВЫСОКОГО " \
  "     УРОВНЯ.    " \
  "                " \
  " *******,ПРАВДА," \
  "SOUND SYSTEM МЫ " \
  "ТАК И НЕ СДЕЛАЛИ" \
  "**** - ОТДЕЛЬНО " \
  "РАБОТАЕТ,А ЗДЕСЬ" \
  "   НЕ ХОЧЕТ.    " \
  "НО ********** МЫ" \
  " С НЕЙ МЕСЯЦ,НЕ " \
  "     МЕНЬШЕ.    " \
  "НУ И НУ ЕЕ ** *." \
  " ЗАТО НЕ СКУЧНО " \
  "      БЫЛО.     " \
  "                " \
  " НУ ВСЕ.******  " \
  "  ДАЛЬШЕ ТЕКСТ  " \
  "    НАБИРАТЬ.   " \
  "                " \
  "КОМУ ЧО НАДО -  " \
  " - ПИШИТЕ ПЫСЬМА" \
  "      НАМ:      " \
  "                " \
  "МИХА САМОЙЛЕНКО " \
  " (2:5064/21.25) " \
  "                " \
  "       И        " \
  "                " \
  "  ЖЕКА ФОМИНОВ  " \
  "(2:5064/11.128) " \
  "      AKA       " \
  "(2:5064/20.128) " \
  "                " \
  "                " \
  "                " \
  "     ХВАТИТ.    " \
  "                " \
  "      1999Г.    " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "      ОГО!      " \
  " ВОТ ЭТО ******!" \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  " *****,*****,ЧО " \
  "ТЕБЕ ЕЩЕ НАДО?! " \
  "                " \
  "  А ХОТЯ ****,  " \
  "  ЖАЛКО,ЧТОЛИ?  " \
  "                " \
  " ПОШЛО ПО-НОВОЙ." \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                " \
  "                "
}, *mtxt=&maintext;

char font[] =
{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0xc0, 0x00,  \
  0x6c, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x6c, 0xfe, 0x6c, 0xfe, 0x6c, 0x00,  \
  0x30, 0xfc, 0xe0, 0x1c, 0xfc, 0x30, 0xcc, 0xd8, 0x30, 0x6c, 0xcc, 0x00,  \
  0x10, 0x10, 0x7c, 0x10, 0x10, 0x00, 0x18, 0x18, 0x30, 0x00, 0x00, 0x00,  \
  0x06, 0x0c, 0x0c, 0x0c, 0x06, 0x00, 0xc0, 0x60, 0x60, 0x60, 0xc0, 0x00,  \
  0xc6, 0x6c, 0xfe, 0x6c, 0xc6, 0x00, 0x30, 0x30, 0xfc, 0x30, 0x30, 0x00,  \
  0x00, 0x00, 0x00, 0x60, 0x60, 0xc0, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00,  \
  0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x0c, 0x18, 0x30, 0x60, 0xc0, 0x00,  \
  0xfe, 0xce, 0xd6, 0xe6, 0xfe, 0x00, 0x38, 0x78, 0xf8, 0x38, 0xfe, 0x00,  \
  0xfe, 0x06, 0xfe, 0xc0, 0xfe, 0x00, 0xfe, 0xc6, 0x1c, 0xc6, 0xfe, 0x00,  \
  0xc6, 0xc6, 0xfe, 0x06, 0x06, 0x00, 0xfe, 0xc0, 0xfe, 0x06, 0xfe, 0x00,  \
  0xfe, 0xc0, 0xfe, 0xc6, 0xfe, 0x00, 0xfe, 0x06, 0x0c, 0x18, 0x18, 0x00,  \
  0xfe, 0xc6, 0x7c, 0xc6, 0xfe, 0x00, 0xfe, 0xc6, 0xfe, 0x06, 0xfe, 0x00,  \
  0x00, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x30, 0x00,  \
  0x18, 0x30, 0x60, 0x30, 0x18, 0x00, 0x00, 0xfc, 0x00, 0xfc, 0x00, 0x00,  \
  0x60, 0x30, 0x18, 0x30, 0x60, 0x00, 0xfe, 0x06, 0x3e, 0x00, 0x30, 0x00,  \
  0xfe, 0xe6, 0xde, 0xc0, 0xfe, 0x00, 0xfe, 0xc6, 0xc6, 0xfe, 0xc6, 0x00,  \
  0xfe, 0xc6, 0xfc, 0xc6, 0xfe, 0x00, 0xfe, 0xc6, 0xc0, 0xc6, 0xfe, 0x00,  \
  0xfc, 0xc6, 0xc6, 0xc6, 0xfc, 0x00, 0xfe, 0xc0, 0xf0, 0xc0, 0xfe, 0x00,  \
  0xfe, 0xc0, 0xf0, 0xc0, 0xc0, 0x00, 0xfe, 0xc0, 0xde, 0xc6, 0xfe, 0x00,  \
  0xc6, 0xc6, 0xfe, 0xc6, 0xc6, 0x00, 0xfe, 0x38, 0x38, 0x38, 0xfe, 0x00,  \
  0x3e, 0x06, 0x06, 0xc6, 0xfe, 0x00, 0xc6, 0xcc, 0xf8, 0xcc, 0xc6, 0x00,  \
  0xc0, 0xc0, 0xc0, 0xc6, 0xfe, 0x00, 0xc6, 0xee, 0xfe, 0xd6, 0xc6, 0x00,  \
  0xc6, 0xe6, 0xf6, 0xde, 0xce, 0x06, 0xfe, 0xc6, 0xc6, 0xc6, 0xfe, 0x00,  \
  0xfe, 0xc6, 0xc6, 0xfe, 0xc0, 0x00, 0xfe, 0xc6, 0xde, 0xce, 0xfe, 0x00,  \
  0xfe, 0xc6, 0xc6, 0xfc, 0xc6, 0x00, 0xfe, 0xc0, 0xfe, 0x06, 0xfe, 0x00,  \
  0xfe, 0x38, 0x38, 0x38, 0x38, 0x00, 0xc6, 0xc6, 0xc6, 0xc6, 0xfe, 0x00,  \
  0xc6, 0xc6, 0xc6, 0x6c, 0x38, 0x00, 0xc6, 0xd6, 0xfe, 0xee, 0xc6, 0x00,  \
  0xc6, 0x6c, 0x38, 0x6c, 0xc6, 0x00, 0xc6, 0xc6, 0xfe, 0x06, 0xfe, 0x00,  \
  0xfe, 0x06, 0x7c, 0xc0, 0xfe, 0x00, 0xfe, 0xc6, 0xc6, 0xfe, 0xc6, 0x00,  \
  0xfe, 0xc0, 0xfe, 0xc6, 0xfe, 0x00, 0xfe, 0xc6, 0xfc, 0xc6, 0xfe, 0x00,  \
  0xfe, 0xc6, 0xc0, 0xc0, 0xc0, 0x00, 0xf8, 0xcc, 0xc6, 0xc6, 0xfc, 0x00,  \
  0xfe, 0xc0, 0xf0, 0xc0, 0xfe, 0x00, 0xd6, 0xd6, 0x7c, 0xd6, 0xd6, 0x00,  \
  0xfe, 0xc6, 0x1c, 0xc6, 0xfe, 0x00, 0xc6, 0xce, 0xde, 0xf6, 0xe6, 0xc0,  \
  0xd6, 0xce, 0xde, 0xf6, 0xe6, 0xc0, 0xc6, 0xcc, 0xf8, 0xcc, 0xc6, 0x00,  \
  0x3e, 0x66, 0x66, 0x66, 0xc6, 0x00, 0xc6, 0xee, 0xfe, 0xd6, 0xc6, 0x00,  \
  0xc6, 0xc6, 0xfe, 0xc6, 0xc6, 0x00, 0xfe, 0xc6, 0xc6, 0xc6, 0xfe, 0x00,  \
  0xfe, 0xc6, 0xc6, 0xc6, 0xc6, 0x00, 0xfe, 0xc6, 0xc6, 0xfe, 0xc0, 0x00,  \
  0xfe, 0xc6, 0xc0, 0xc6, 0xfe, 0x00, 0xfe, 0x38, 0x38, 0x38, 0x38, 0x00,  \
  0xc6, 0xc6, 0xfe, 0x06, 0xfe, 0x00, 0xfe, 0xd6, 0xd6, 0xfe, 0x10, 0x00,  \
  0xc6, 0x6c, 0x38, 0x6c, 0xc6, 0x00, 0xc6, 0xc6, 0xc6, 0xc6, 0xff, 0x03,  \
  0xc6, 0xc6, 0xfe, 0x06, 0x06, 0x00, 0xd6, 0xd6, 0xd6, 0xd6, 0xfe, 0x00,  \
  0xd6, 0xd6, 0xd6, 0xd6, 0xff, 0x03, 0xe0, 0x60, 0x7e, 0x66, 0x7e, 0x00,  \
  0xc6, 0xc6, 0xfa, 0xca, 0xfa, 0x00, 0xc0, 0xc0, 0xfe, 0xc6, 0xfe, 0x00,  \
  0xfe, 0xc6, 0x1e, 0xc6, 0xfe, 0x00, 0xde, 0xd6, 0xf6, 0xd6, 0xde, 0x00,  \
  0xfe, 0xc6, 0xc6, 0x7e, 0xc6, 0x00
}, *fntptr = &font;

char ball[] =
{
  0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, \
  0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, \
  0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, \
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
  0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, \
  0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, \
  0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00
}, *bptr = &ball;

void txtline(void);
#pragma aux txtline =           \
  "push ds"                     \
  "mov dssav, ds"               \
  "mov ax, 16"                  \
  "mul curline"                 \
  "les di, txtbuf"              \
  "add di, 0x3163"              \
  "lds si, mtxt"                \
  "add si, ax"                  \
  "mov cx, 16"                  \
  "tl1:"                        \
  "lodsb"                       \
  "and al, al"                  \
  "jnz nendtxt"                 \
  "mov curpos, 0"               \
  "mov curline, 0"              \
  "jmp tl8"                     \
  "nendtxt:"                    \
  "push cx"                     \
  "cmp al, 128"                 \
  "jc llat"                     \
  "sub al, 37"                  \
  "llat:"                       \
  "sub al, 32"                  \
  "xor ah, ah"                  \
  "mov cl, 6"                   \
  "mul cl"                      \
  "add ax, curpos"              \
  "push si"                     \
  "push ds"                     \
  "mov ds, dssav"               \
  "lds si, fntptr"              \
  "add si, ax"                  \
  "lodsb"                       \
  "mov cx, 8"                   \
  "tl2:"                        \
  "xor dl, dl"                  \
  "rcl al, 1"                   \
  "jnc tl3"                     \
  "mov dl, 0x7f"                \
  "tl3:"                        \
  "mov es:[di], dl"             \
  "inc di"                      \
  "loop tl2"                    \
  "pop ds"                      \
  "pop si"                      \
  "pop cx"                      \
  "loop tl1"                    \
  "inc curpos"                  \
  "cmp curpos, 6"               \
  "jc tl8"                      \
  "mov curpos, 0"               \
  "inc curline"                 \
  "tl8:"                        \
  "pop ds"                      \
  modify [ax cx dx di si];

void scrollup(void);
#pragma aux scrollup =          \
  "push ds"                     \
  "les di, txtbuf"              \
  "lds si, txtbuf"              \
  "add di, 0x81"                \
  "add si, 0x102"               \
  "mov cx, 0x3162"              \
  "rep movsb"                   \
  "pop ds"                      \
  modify [di si cx];

void copyline(word, word, word);
#pragma aux copyline =          \
  "push ds"                     \
  "les di, scr"                 \
  "lds si, txtbuf"              \
  "add si, bx"                  \
  "shl bx, 7"                   \
  "add si, bx"                  \
  "mov bx, 320"                 \
  "mul bx"                      \
  "add ax, cx"                  \
  "add di, ax"                  \
  "mov cx, 129"                 \
  "cl1:"                        \
  "lodsb"                       \
  "and al, al"                  \
  "jnz cl2"                     \
  "mov bl, es:[di]"             \
  "cmp bl, 0xff"                \
  "jc cl2"                      \
  "mov al, 0x20"                \
  "cl2:"                        \
  "stosb"                       \
  "loop cl1"                    \
  "pop ds"                      \
  parm [bx] [cx] [ax]           \
  modify[ax bx cx];

void print(void*);
#pragma aux print =             \
  "push ds"                     \
  "mov ds, si"                  \
  "mov si, ax"                  \
  "mov ah, 0x02"                \
  "prn1:"                       \
  "mov dl, ds:[si]"             \
  "and dl, dl"                  \
  "jz endprn"                   \
  "int 0x21"                    \
  "inc si"                      \
  "jmp prn1"                    \
  "endprn:"                     \
  "pop ds"                      \
  parm [si ax]                  \
  modify [si ax dx];

void *malloc(word);
#pragma aux malloc =            \
  "mov ah, 0x48"                \
  "shr bx, 4"                   \
  "int 0x21"                    \
  "mov bx, ax"                  \
  "xor ax, ax"                  \
  value [ax bx]                 \
  parm [bx]                     \
  modify [ax bx];

void free(void*);
#pragma aux free =              \
  "mov ah, 0x49"                \
  "int 0x21"                    \
  parm [es ax]                  \
  modify [ax];

void setmode(byte);
#pragma aux setmode =           \
  "xor ah, ah"                  \
  "int  0x10"                   \
  parm [al]                     \
  modify [ax];

void waitretrace(void);
#pragma aux waitretrace =       \
  "mov  dx, 0x3da"              \
  "waitr1:"                     \
  "in   al, dx"                 \
  "test al, 08h"                \
  "jz  waitr1"                  \
  modify [ax dx];

void clear(void*, word);
#pragma aux clear =             \
  "mov es, si"                  \
  "mov di, ax"                  \
  "xor al, al"                  \
  "rep stosb"                   \
  parm [si ax] [cx]             \
  modify [ax cx di];

void ptbl(void);
#pragma aux ptbl =              \
  "push ds"                     \
  "lds si, scr"                 \
  "mov ax, 0xa000"              \
  "mov es, ax"                  \
  "xor di, di"                  \
  "mov cx, 0x3e80"              \
  "rep movsd"                   \
  "pop ds"                      \
  modify [ax cx di si es];

char escpressed(void);
#pragma aux escpressed =        \
  "in  al, 0x60"                \
  "dec al"                      \
  value [al]                    \
  modify [ax];

void copy1(void);
#pragma aux copy1 =             \
  "push ds"                     \
  "les di, scr1"                \
  "lds si, scr"                 \
  "mov cx, 0x3e80"              \
  "rep movsd"                   \
  "pop ds"                      \
  modify [cx];

void blur(void);
#pragma aux blur =              \
  "push ds"                     \
  "les di, scr"                 \
  "add di, 321"                 \
  "lds si, scr1"                \
  "add si, 321"                 \
  "mov cx, 198"                 \
  "blur1:"                      \
  "push cx"                     \
  "mov cx, 318"                 \
  "blur2:"                      \
  "xor bh, bh"                  \
  "xor ax, ax"                  \
  "mov bl, ds:[si-321]"         \
  "add ax, bx"                  \
  "mov bl, ds:[si-320]"         \
  "add ax, bx"                  \
  "mov bl, ds:[si-319]"         \
  "add ax, bx"                  \
  "mov bl, ds:[si-1]"           \
  "add ax, bx"                  \
  "mov bl, ds:[si]"             \
  "add ax, bx"                  \
  "mov bl, ds:[si+1]"           \
  "add ax, bx"                  \
  "mov bl, ds:[si+319]"         \
  "add ax, bx"                  \
  "mov bl, ds:[si+320]"         \
  "add ax, bx"                  \
  "mov bl, ds:[si+321]"         \
  "add ax, bx"                  \
  "mov bl, 10"                  \
  "div bl"                      \
  "stosb"                       \
  "inc si"                      \
  "loop blur2"                  \
  "add di, 2"                   \
  "add si, 2"                   \
  "pop cx"                      \
  "loop blur1"                  \
  "pop ds"                      \
  modify [ax bx cx si di];

float mysin(float angle)
{
  float res=0;

  _asm
  {
    fld angle
    fsin
    fstp res
  }
  return res;
}

void charxy(byte, word, word, byte);
#pragma aux charxy =            \
  "push ds"                     \
  "push dx"                     \
  "les di, scr"                 \
  "push cx"                     \
  "mov cx, 320"                 \
  "mul cx"                      \
  "add ax, bx"                  \
  "add di, ax"                  \
  "pop ax"                      \
  "cmp al, 128"                 \
  "jc lat"                      \
  "sub al, 37"                  \
  "lat:"                        \
  "sub al, 32"                  \
  "xor ah, ah"                  \
  "mov cl, 6"                   \
  "mul cl"                      \
  "lds si, fntptr"              \
  "add si, ax"                  \
  "pop dx"                      \
  "mov cx, 6"                   \
  "txt1a:"                      \
  "push cx"                     \
  "mov cx, 8"                   \
  "lodsb"                       \
  "txt2:"                       \
  "rcl al, 1"                   \
  "jnc txt3"                    \
  "mov es:[di], dl"             \
  "txt3:"                       \
  "inc di"                      \
  "loop txt2"                   \
  "pop cx"                      \
  "add di, 312"                 \
  "loop txt1a"                  \
  "pop ds"                      \
  "end:"                        \
  parm [cl] [bx] [ax] [dl]      \
  modify [ax bx cx di si];

void drawball(word, word);
#pragma aux drawball =          \
  "push ds"                     \
  "mov dx, 320"                 \
  "mul dx"                      \
  "add ax, bx"                  \
  "les di, scr"                 \
  "add di, ax"                  \
  "lds si, bptr"                \
  "mov cx, 11"                  \
  "aaa1:"                       \
  "push cx"                     \
  "mov cx, 11"                  \
  "aaa2:"                       \
  "lodsb"                       \
  "and al, al"                  \
  "jz aaa3"                     \
  "mov es:[di], al"             \
  "aaa3:"                       \
  "inc di"                      \
  "loop aaa2"                   \
  "pop cx"                      \
  "add di, 309"                 \
  "loop aaa1"                   \
  "pop ds"                      \
  parm [bx] [ax]                \
  modify [ax bx cx dx si di];

void setfirepalette(void);
#pragma aux setfirepalette =    \
  "mov dx, 0x3c8"               \
  "xor al, al"                  \
  "out dx, al"                  \
  "mov cx, 0x40"                \
  "inc dx"                      \
  "aaa0:"                       \
  "xor al, al"                  \
  "out dx, al"                  \
  "out dx, al"                  \
  "mov al, 0x40"                \
  "sub al, cl"                  \
  "out dx, al"                  \
  "loop aaa0"                   \
  "mov cx, 0x40"                \
  "aaa1:"                       \
  "mov al, 0x40"                \
  "sub al, cl"                  \
  "out dx, al"                  \
  "xor al, al"                  \
  "out dx, al"                  \
  "out dx, al"                  \
  "loop aaa1"                   \
  "mov cx, 0x40"                \
  "aaa2:"                       \
  "mov al, 0x3f"                \
  "out dx, al"                  \
  "mov al, 0x40"                \
  "sub al, cl"                  \
  "out dx, al"                  \
  "xor al, al"                  \
  "out dx, al"                  \
  "loop aaa2"                   \
  "mov cx, 0x40"                \
  "aaa3:"                       \
  "push ax"                     \
  "mov al, 0x3f"                \
  "out dx, al"                  \
  "out dx, al"                  \
  "mov al, 0x40"                \
  "sub al, cl"                  \
  "out dx, al"                  \
  "loop aaa3"                   \
  modify [ax cx dx];

void main(void)
{
  float at=0, att=0, attt=pi/300, x, y, x1, y1, axy=0;
  byte i, rx=0, ry=0, aa=0, grtz=8, cntr=0;
  word grc=0;

  scr=malloc(0xfa00);
  scr1=malloc(0xfa00);
  txtbuf=malloc(0x3270);
  setmode(0x13);
  clear(scr, 0xfa00);
  clear(txtbuf, 0x3270);
  ptbl();
  setfirepalette();
  while(escpressed())
  {
    for (i=0; i<n; i++)
    {
      x=rx*mysin(axy*i+axy);
      y=ry*mysin(axy*i-axy+pi/2);
      x1=rx*mysin(axy*i-axy);
      y1=ry*mysin(axy*i+axy+pi/2);
      drawball(xc+x,yc+y);
      drawball(xc+x1,yc+y1);
    }
    for (i=grtz; i<8; i++)
      charxy(greetz1[i],5+8*(i-grtz),5,0xbf);
    if (cntr%3&&grtz&&aa>98)
      grtz--;
    if (cntr>25&&aa>98)
      for (i=0; i<20; i++)
        charxy(greetz[grc+i],10+8*i,12,255);
    copy1();
    if (cntr<25&&aa>98)
      for (i=0; i<20; i++)
        charxy(greetz[grc+i],10+8*i,12,255);
    if (rx<140)
      rx++;
    if (ry<80)
      ry++;
    for (i=0; i<=12; i++)
      charxy(text[i],i*8+5,190-abs(15*mysin(i*pi/10+at)),100+10*i);
    if (att>pi/6||att<-pi/6)
      attt=-attt;
    for (i=0;i<=aa;i++)
      copyline(i,180+4*mysin(i*att+at),i+3);
    if (aa<99&&rx>130)
      aa++;
    if (!(cntr%4)&&aa==99)
    {
      scrollup();
      txtline();
    }
    if (cntr==30)
      grc+=20;
    if (!greetz[grc])
      grc=0;
    at+=pi/15;
    att+=attt;
    axy+=a1xy;
    if (cntr>30)
      cntr=0;
    if (aa>98)
      cntr++;
    waitretrace();
    ptbl();
    blur();
   }
   setmode(3);
   free (scr1);
   free (scr);
   free (txtbuf);
   print("Sponsored by [******]___________");
*
