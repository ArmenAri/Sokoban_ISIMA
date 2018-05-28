#pragma once

#ifndef _COLORS_
#define _COLORS_

/*
*@param : param (entre 30 et 37 pour la couleur du texte et entre 40 et 47 pour la couleur du fond)
*@brief : colore la console avec la couleur param
*/

#define NO_COLOR "0"
#define COLOR_BLACK "40"
#define COLOR_BLUE "44"
#define COLOR_GREEN "42"
#define COLOR_CYAN "46"
#define COLOR_RED "41"
#define COLOR_PURPLE "45"
#define COLOR_YELLOW "43"
#define COLOR_WHITE "47"

#define color(param) printf("\033[%sm", param)

#endif
