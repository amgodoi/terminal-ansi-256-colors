/**
 * main.c
 */
#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <wchar.h>
#include <locale.h>

#define COLOR_256 L"\033[38;5;%um"
#define COLOR_RESET_TO_DEFAULT L"\033[0m"

void change_terminal_color(uint8_t color);
void reset_terminal_to_default_color();

int main()
{
	(void) setlocale(LC_CTYPE, "");

    wchar_t *s = L"Hello, world!!!";

    for (uint16_t color = 0; color < 256; color++) {
        change_terminal_color(color);
        wprintf(L"%3u - %ls\n", color, s);
    }

    reset_terminal_to_default_color();
    
	return 0;
}

void change_terminal_color(uint8_t color)
{
    wprintf(COLOR_256, color);
}

void reset_terminal_to_default_color() 
{
    wprintf(L"%ls", COLOR_RESET_TO_DEFAULT);
}

