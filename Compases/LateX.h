#pragma once
#include <string>

#define _S(st)          std::string(st)

#define NOTA_REDONDA       _S("\\wh{h} ")
#define NOTA_BLANCAP       _S("\\hap{h} ")
#define NOTA_BLANCA        _S("\\ha{h} ")
#define NOTA_NEGRAP        _S("\\qap{h} ")
#define NOTA_NEGRA         _S("\\qa{h} ")
#define NOTA_CORCHEAP      _S("\\cap{h} ")
#define NOTA_CORCHEA       _S("\\ca{h} ")
#define NOTA_SEMICORCHEAP  _S("\\ccap{h} ")
#define NOTA_SEMICORCHEA   _S("\\cca{h} ")
#define NOTA_FUSAP         _S("\\cccap{h} ")
#define NOTA_FUSA          _S("\\ccca{h} ")
#define NOTA_SEMIFUSAP     _S("\\ccccap{h} ")
#define NOTA_SEMIFUSA      _S("\\cccca{h} ")

#define SILENCIO_REDONDA       _S("\\pause ")
#define SILENCIO_BLANCAP       _S("\\hpausep ")
#define SILENCIO_BLANCA        _S("\\hpause ")
#define SILENCIO_NEGRAP        _S("\\qpp ")
#define SILENCIO_NEGRA         _S("\\soupir ")
#define SILENCIO_CORCHEAP      _S("\\dsp ")
#define SILENCIO_CORCHEA       _S("\\ds ")
#define SILENCIO_SEMICORCHEAP  _S("\\qsp ")
#define SILENCIO_SEMICORCHEA   _S("\\qs ")
#define SILENCIO_FUSAP         _S("\\hsp ")
#define SILENCIO_FUSA          _S("\\hs ")
#define SILENCIO_SEMIFUSAP     _S("\\qqsp ")
#define SILENCIO_SEMIFUSA      _S("\\qqs ")

#define N_REDONDA       _S("\\NOTEs \\wh{h} \\enotes")
#define N_BLANCAP       _S("\\NOTesp \\hap{h} \\enotes")
#define N_BLANCA        _S("\\NOTes \\ha{h} \\enotes")
#define N_NEGRAP        _S("\\NOtesp \\qap{h} \\enotes")
#define N_NEGRA         _S("\\NOtes \\qa{h} \\enotes")
#define N_CORCHEAP      _S("\\notesp \\cap{h} \\enotes")
#define N_CORCHEA       _S("\\Notes \\ca{h} \\enotes")
#define N_SEMICORCHEAP  _S("\\notesp \\ccap{h} \\enotes")
#define N_SEMICORCHEA   _S("\\notes \\cca{h} \\enotes")
#define N_FUSAP         _S("\\notes \\cccap{h} \\enotes")
#define N_FUSA          _S("\\notes \\ccca{h} \\enotes")
#define N_SEMIFUSAP     _S("\\notes \\ccccap{h} \\enotes")
#define N_SEMIFUSA      _S("\\notes \\cccca{h} \\enotes")

#define S_REDONDA       _S("\\NOTEs \\pause \\enotes")
#define S_BLANCAP       _S("\\NOTesp \\hpausep \\enotes")
#define S_BLANCA        _S("\\NOTes \\hpause \\enotes")
#define S_NEGRAP        _S("\\NOtesp \\soupirp \\enotes")
#define S_NEGRA         _S("\\NOtes \\soupir \\enotes")
#define S_CORCHEAP      _S("\\notesp \\dsp \\enotes")
#define S_CORCHEA       _S("\\Notes \\ds \\enotes")
#define S_SEMICORCHEAP  _S("\\notesp \\qsp \\enotes")
#define S_SEMICORCHEA   _S("\\notes \\qs \\enotes")
#define S_FUSAP         _S("\\notes \\hsp \\enotes")
#define S_FUSA          _S("\\notes \\hs \\enotes")
#define S_SEMIFUSAP     _S("\\notes \\qqsp \\enotes")
#define S_SEMIFUSA      _S("\\notes \\qqs \\enotes")

#define COMPASS         _S("\\bar ")
#define BEGIN_NOTES     _S("\\notes ")
#define END_NOTES       _S("\\enotes ")
#define BEGIN_LIGADURA  _S("\\itied0e ")
#define END_LIGADURA    _S("\\ttie0 ")
#define BEGIN_LIGADURA_  _S("\\islurd0 ")
#define END_LIGADURA_    _S("\\tslur0 ")

#define ERROR           _S("%ERROR \n")

#define REDONDA         1
#define BLANCA          2
#define NEGRA           4
#define CORCHEA         8
#define SEMICORCHEA     16
#define FUSA            32
#define SEMIFUSA        64
