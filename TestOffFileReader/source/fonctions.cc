
/*! \file fonctions.cc
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier fonctions.cc
 * \brief regroupe les fonctions normales
 */

#include "fonctions.hh"




//permet de retourner le point de coord barycentrique lambda
Point ex7(Point P, Point Q, float lambda){
  
  Vecteur U(P,Q);
  Point R((P.abcisse() + (lambda * U.abcisse())),(P.ordonnee() + (lambda * U.ordonnee())));
  return(R);
  
}













