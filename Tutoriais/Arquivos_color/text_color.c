#include <stdio.h>

/* Prefixo T = TEXT */
/* Prefixo B = BACKGROUND */
/* Prefixo TB = TEXT BOLD */
/* Prefixo TU = TEXT UNDERSOCRED */

/* Standard colors and ANSI escape sequence */
#define  CSI         "\x1B["
#define  RESET       "0m"
#define  BOLD_OFF    "21m"
#define  UNSCR_OFF   "24m"

/* Text colors */
#define  T_BLACK     "30m"
#define  T_RED       "31m"
#define  T_GREEN     "32m"
#define  T_YELLOW    "33m"
#define  T_BLUE      "34m"
#define  T_PURPLE    "35m"
#define  T_CYAN      "36m"
#define  T_WHITE     "37m"

/* Background */
#define  B_BLACK     "40m"
#define  B_RED       "41m"
#define  B_GREEN     "42m"
#define  B_YELLOW    "43m"
#define  B_BLUE      "44m"
#define  B_PURPLE    "45m"
#define  B_CYAN      "46m"
#define  B_WHITE     "47m"
#define  B_DEFAULT   "49m"

/* Bold colored text */
#define TB_BLACK     "30;1m"
#define TB_RED       "31;1m"
#define TB_GREEN     "32;1m"
#define TB_YELLOW    "33;1m"
#define TB_BLUE      "34;1m"
#define TB_PURPLE    "35;1m"
#define TB_CYAN      "36;1m"
#define TB_WHITE     "37;1m"

/* Underscored colored text */
#define TU_BLACK     "30;4m"
#define TU_RED       "31;4m"
#define TU_GREEN     "32;4m"
#define TU_YELLOW    "33;4m"
#define TU_BLUE      "34;4m"
#define TU_PURPLE    "35;4m"
#define TU_CYAN      "36;4m"
#define TU_WHITE     "37;4m"




int main () {

    printf("%s%sThis text is black%s%s\n",  CSI, T_BLACK,  CSI, T_BLACK);
    printf("%s%sThis text is red%s%s\n",    CSI, T_RED,    CSI, T_BLACK);
    printf("%s%sThis text is green%s%s\n",  CSI, T_GREEN,  CSI, T_BLACK);
    printf("%s%sThis text is yellow%s%s\n", CSI, T_YELLOW, CSI, T_BLACK);
    printf("%s%sThis text is blue%s%s\n",   CSI, T_BLUE,   CSI, T_BLACK);
    printf("%s%sThis text is purple%s%s\n", CSI, T_PURPLE, CSI, T_BLACK);
    printf("%s%sThis text is cyan%s%s\n",   CSI, T_CYAN,   CSI, T_BLACK);
    printf("%s%sThis text is white%s%s\n",  CSI, T_WHITE,  CSI, T_WHITE);
    printf("\n");
    printf("%s%sThis backgroud is black%s%s\n",  CSI, B_BLACK,  CSI, B_DEFAULT);
    printf("%s%sThis backgroud is red%s%s\n",    CSI, B_RED,    CSI, B_DEFAULT);
    printf("%s%sThis backgroud is green%s%s\n",  CSI, B_GREEN,  CSI, B_DEFAULT);
    printf("%s%sThis backgroud is yellow%s%s\n", CSI, B_YELLOW, CSI, B_DEFAULT);
    printf("%s%sThis backgroud is blue%s%s\n",   CSI, B_BLUE,   CSI, B_DEFAULT);
    printf("%s%sThis backgroud is purple%s%s\n", CSI, B_PURPLE, CSI, B_DEFAULT);
    printf("%s%sThis backgroud is cyan%s%s\n",   CSI, B_CYAN,   CSI, B_DEFAULT);
    printf("%s%sThis backgroud is white%s%s\n",  CSI, B_WHITE,  CSI, B_DEFAULT);
    printf("\n");
    printf("%s%sBold black text%s%s\n",    CSI, TB_BLACK,  CSI, RESET);
    printf("%s%sBold red text%s%s\n",      CSI, TB_RED,    CSI, RESET);
    printf("%s%sBold green text%s%s\n",    CSI, TB_GREEN,  CSI, RESET);
    printf("%s%sBold yellow text%s%s\n",   CSI, TB_YELLOW, CSI, RESET);
    printf("%s%sBold blue text%s%s\n",     CSI, TB_BLUE, 	CSI, RESET);
    printf("%s%sBold purple text%s%s\n",   CSI, TB_PURPLE, CSI, RESET);
    printf("%s%sBold cyan text%s%s\n",     CSI, TB_CYAN, 	CSI, RESET);
    printf("%s%sBold white text%s%s\n",    CSI, TB_WHITE,	CSI, RESET);
    printf("\n");
    printf("%s%sUnderscored black text%s%s\n", 	CSI, TU_BLACK,	CSI, RESET);
    printf("%s%sUnderscored red text%s%s\n", 		CSI, TU_RED, 	CSI, RESET);
    printf("%s%sUnderscored green text%s%s\n", 	CSI, TU_GREEN, 	CSI, RESET);
    printf("%s%sUnderscored yellow text%s%s\n", 	CSI, TU_YELLOW, CSI, RESET);
    printf("%s%sUnderscored blue text%s%s\n", 		CSI, TU_BLUE,	CSI, RESET);
    printf("%s%sUnderscored purple text%s%s\n", 	CSI, TU_PURPLE, CSI, RESET);
    printf("%s%sUnderscored cyan text%s%s\n", 		CSI, TU_CYAN, 	CSI, RESET);
    printf("%s%sUnderscored white text%s%s\n", 	CSI, TU_WHITE, 	CSI, RESET);
    printf("\n");
    return 0;
}
