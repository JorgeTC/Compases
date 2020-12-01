#include "Compas.h"
#include "MathGen.h"
#include "LateX.h"
#include <math.h>
#include <iostream>

Compas::Compas(int notas) {
   long long int options = pow(3, notas);
   m_notas = notas;

   OpenFile();

   for (long long int i = pow(3, notas - 1); i < options; i++){
      Base3(i, m_pulsos, m_notas);
      if (IsValid()) {
         print();
      }
   }

   cierre();
   LatexFile.close();
}

bool Compas::IsValid()
{
   bool LastSilence = false;
   for (int i = 0; i < m_notas; i++) {
      if (IS_SILENCIO(m_pulsos[i])) {
         if (LastSilence)
            return false;
         LastSilence = true;
      }
      else if (IS_NOTA(m_pulsos[i]))
         LastSilence = false;
   }
}

void
Compas::print()
{
   bool bNote;
   int nLen;

   if (!firstCompas)
      LatexFile << COMPASS << "\n";
   else
      firstCompas = false;
   for (int i = 0; i < m_notas; i++) {
      bNote = IS_NOTA(m_pulsos[i]);
      nLen = 1;
      for (int j = i + 1; j < m_notas; j++) {
         if (IS_NADA(m_pulsos[j]))
            nLen++;
         else
            break;
      }
      i += nLen - 1;
      GetSimbol(bNote, nLen);
   }
}

void
Compas::GetSimbol(bool bNote, int duracion)
{
   double proportion = double(duracion) / double(m_notas);
   if (bNote) {
      if (proportion == LEN_REDONDA)
         LatexFile << N_REDONDA;
      else if (proportion == LEN_BLANCAP)
         LatexFile << N_BLANCAP;
      else if (proportion == LEN_BLANCA)
         LatexFile << N_BLANCA;
      else if (proportion == LEN_NEGRAP)
         LatexFile << N_NEGRAP;
      else if (proportion == LEN_NEGRA)
         LatexFile << N_NEGRA;
      else if (proportion == LEN_CORCHEAP)
         LatexFile << N_CORCHEAP;
      else if (proportion == LEN_CORCHEA)
         LatexFile << N_CORCHEA;
      else if (proportion == LEN_SEMICORCHEAP)
         LatexFile << N_SEMICORCHEAP;
      else if (proportion == LEN_SEMICORCHEA)
         LatexFile << N_SEMICORCHEA;
      else if (proportion == LEN_FUSAP)
         LatexFile << N_FUSAP;
      else if (proportion == LEN_FUSA)
         LatexFile << N_FUSA;
      else if (proportion == LEN_SEMIFUSAP)
         LatexFile << N_SEMIFUSAP;
      else if (proportion == LEN_SEMIFUSA)
         LatexFile << N_SEMIFUSA;
      else
         SpeciaNote(duracion);
   }
   else {
      if (proportion == LEN_REDONDA)
         LatexFile << S_REDONDA;
      else if (proportion == LEN_BLANCAP)
         LatexFile << S_BLANCAP;
      else if (proportion == LEN_BLANCA)
         LatexFile << S_BLANCA;
      /*else if (proportion == LEN_NEGRAP)
         LatexFile << S_NEGRAP;*/
      else if (proportion == LEN_NEGRA)
         LatexFile << S_NEGRA;
      else if (proportion == LEN_CORCHEAP)
         LatexFile << S_CORCHEAP;
      else if (proportion == LEN_CORCHEA)
         LatexFile << S_CORCHEA;
      else if (proportion == LEN_SEMICORCHEAP)
         LatexFile << S_SEMICORCHEAP;
      else if (proportion == LEN_SEMICORCHEA)
         LatexFile << S_SEMICORCHEA;
      else if (proportion == LEN_FUSAP)
         LatexFile << S_FUSAP;
      else if (proportion == LEN_FUSA)
         LatexFile << S_FUSA;
      else if (proportion == LEN_SEMIFUSAP)
         LatexFile << S_SEMIFUSAP;
      else if (proportion == LEN_SEMIFUSA)
         LatexFile << S_SEMIFUSA;
      else
         SpecialSilence(duracion);
   }
}

void
Compas::SpeciaNote(int duracion){
   // convierto la longitud a semifusas
   int LenSemiFusas = duracion * double(SEMIFUSA) / double(m_notas);
   bool Descomposicion[7];
   Base2(LenSemiFusas, Descomposicion, 7);

   int endLigadura = LowestDescomposicion(Descomposicion);
   LatexFile << BEGIN_NOTES;
   LatexFile << BEGIN_LIGADURA;
   if (Descomposicion[0])
      LatexFile << NOTA_REDONDA;
   if (endLigadura == 1)
      LatexFile << END_LIGADURA;
   if (Descomposicion[1])
      LatexFile << NOTA_BLANCA;
   if (endLigadura == 2)
      LatexFile << END_LIGADURA;
   if (Descomposicion[2])
      LatexFile << NOTA_NEGRA;
   if (endLigadura == 3)
      LatexFile << END_LIGADURA;
   if (Descomposicion[3])
      LatexFile << NOTA_CORCHEA;
   if (endLigadura == 4)
      LatexFile << END_LIGADURA;
   if (Descomposicion[4])
      LatexFile << NOTA_SEMICORCHEA;
   if (endLigadura == 5)
      LatexFile << END_LIGADURA;
   if (Descomposicion[5])
      LatexFile << NOTA_FUSA;
   if (endLigadura == 6)
      LatexFile << END_LIGADURA;
   if (Descomposicion[6])
      LatexFile << NOTA_SEMIFUSA;
   LatexFile << END_NOTES;
}

void
Compas::SpecialSilence(int duracion)
{
   // convierto la longitud a semifusas
   int LenSemiFusas = duracion * double(SEMIFUSA) / double(m_notas);
   bool Descomposicion[7];
   Base2(LenSemiFusas, Descomposicion, 7);

   LatexFile << BEGIN_NOTES;
   if (Descomposicion[0])
      LatexFile << SILENCIO_REDONDA;
   if (Descomposicion[1])
      LatexFile << SILENCIO_BLANCA;
   if (Descomposicion[2])
      LatexFile << SILENCIO_NEGRA;
   if (Descomposicion[3])
      LatexFile << SILENCIO_CORCHEA;
   if (Descomposicion[4])
      LatexFile << SILENCIO_SEMICORCHEA;
   if (Descomposicion[5])
      LatexFile << SILENCIO_FUSA;
   if (Descomposicion[6])
      LatexFile << SILENCIO_SEMIFUSA;
   LatexFile << END_NOTES;
}

void
Compas::OpenFile(){
   switch (m_notas) {
   case  REDONDA:
      LatexFile.open("C:\\Users\\usuario\\Desktop\\Jorges things\\Partituras\\Compas\\Redondas.tex");
      break;
   case BLANCA:
      LatexFile.open("C:\\Users\\usuario\\Desktop\\Jorges things\\Partituras\\Compas\\Blancas.tex");
      break;
   case NEGRA:
      LatexFile.open("C:\\Users\\usuario\\Desktop\\Jorges things\\Partituras\\Compas\\Negras.tex");
      break;
   case CORCHEA:
      LatexFile.open("C:\\Users\\usuario\\Desktop\\Jorges things\\Partituras\\Compas\\Corcheas.tex");
      break;
   case SEMICORCHEA:
      LatexFile.open("C:\\Users\\usuario\\Desktop\\Jorges things\\Partituras\\Compas\\Semicorcheas.tex");
      break;
   case FUSA:
      LatexFile.open("C:\\Users\\usuario\\Desktop\\Jorges things\\Partituras\\Compas\\Fusa.tex");
      break;
   case SEMIFUSA:
      LatexFile.open("C:\\Users\\usuario\\Desktop\\Jorges things\\Partituras\\Compas\\Semifusa.tex");
      break;
   }

   preambulo();
}

void
Compas::preambulo()
{
   LatexFile << "\\documentclass[12pt, a4paper]{article}\n";
   LatexFile << "\\usepackage[utf8]{inputenc}\n";
   LatexFile << "\\usepackage[spanish]{babel}\n\\usepackage{amsmath}\n";
   LatexFile << "\\usepackage{musixtex}\n";
   LatexFile << "\\usepackage{amsfonts}\n";
   LatexFile << "\\usepackage{amssymb}\n";
   LatexFile << "\\parindent = 0cm\n";
   LatexFile << "\\begin{document}\n";

   LatexFile << "\\begin{music}\n";
   LatexFile << "\\setlines 1{0}\n";
   LatexFile << "\\setclefsymbol 1\\empty\n";
   LatexFile << "\\startpiece\n";
}

void Compas::cierre()
{
   LatexFile << "\\endpiece\n";
   LatexFile << "\\end{music}\n";
   LatexFile << "\\end{document}\n";
}
