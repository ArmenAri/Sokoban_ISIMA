#pragma once

#ifndef _COLORS_
#define _COLORS_

/*
*@param : param (entre 30 et 37 pour la couleur du texte et entre 40 et 47 pour la couleur du fond)
*@brief : colore la console avec la couleur param
*/
#define color(param) printf("\033[%sm",param)

#endif
