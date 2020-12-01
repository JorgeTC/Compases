#pragma once
#include <fstream>

#define NADA      int(0)
#define NOTA      int(1)
#define SILENCIO  int(2)

#define IS_NADA(b)      (!b[0])
#define IS_NOTA(b)      (!IS_NADA(b) && b[1])
#define IS_SILENCIO(b)  (!IS_NADA(b) && !b[1])
class Compas
{
   bool m_pulsos[64][2];
   int m_notas;
   bool firstCompas = true;
   std::ofstream LatexFile;
public:
   Compas(int notas);
private:
   bool IsValid();
   void print();
   void GetSimbol(bool bNote, int duracion);

   void SpeciaNote(int duracion);
   void SpecialSilence(int duracion);

   void OpenFile();
   void preambulo();
   void cierre();
};

#define LEN_REDONDA        double(1)/double(1)
#define LEN_BLANCAP        double(3)/double(4)
#define LEN_BLANCA         double(1)/double(2)
#define LEN_NEGRAP         double(3)/double(8)
#define LEN_NEGRA          double(1)/double(4)
#define LEN_CORCHEAP       double(3)/double(16)
#define LEN_CORCHEA        double(1)/double(8)
#define LEN_SEMICORCHEAP   double(3)/double(32)
#define LEN_SEMICORCHEA    double(1)/double(16)
#define LEN_FUSAP          double(3)/double(64)
#define LEN_FUSA           double(1)/double(32)
#define LEN_SEMIFUSAP      double(3)/double(128)
#define LEN_SEMIFUSA       double(1)/double(64)

