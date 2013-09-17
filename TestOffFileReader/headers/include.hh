
/*! \file include.hh
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier include.hh
 * \brief inclusion des headers
*/

#ifndef __INCLUDE_HH_
#define __INCLUDE_HH_

#include <math.h>//bibliotheque de math 
#include <time.h>//bibliotheque pour le temps 
#include <stdlib.h>//bibliotheque std 
#include <stdio.h>//bibliotheque entree sortie 
#include <iostream>//bibliotheque de lecture de fichier
#include <fstream>

#include <QApplication>
#include <QtGui>
#include <QWidget>
#include <QGradient>
#include <QPen>
#include <iostream>//bibliotheque de lecture de fichier
#include <vector>
#include <algorithm>
  

/*! \namespace std
 * \brief Permet d'utiliser les fonctions de lecture et d'ecriture standard
 */
using namespace std;

//on defini une constante pour pi
const float Pi = 3.141592;

const int NB = 10;


class erreur
{
private:
  char* desc;
public:  
  erreur (void)
  {
  }
  
  erreur (char* d)
  {
    desc = d;
  }
  
  erreur (const erreur &source)
  {
    desc = source.desc;
  }
  ~erreur(void)
  {
  }
  char* get_desc(void)const throw()
  {
    return(desc);
  }
};


//#include "classepoint.hh"
class Point3d;



/*! \struct Polyedre
 * \author Paul BERNARD
 * \version 0.1
 * \brief classe Polyedre
 *
 */
typedef struct Polyedre {
  int nbface;/*!< nb de face du polyedre*/
  int * nbpointbyface;/*!< nb de point par face du polyedre*/
  Point3d** ttabpts3d;/*!< tab des points */
}Polyedre;



/*! \fn void delete_polyedre(Polyedre &poly3d) 
 * \author  Paul BERNARD <paul.bernard@eisti.fr> 
 * \version 0.1 
 *           Creation de la fonction
 * 
 * \param poly3d : un polyedre
 * 
 * \brief permet de delete un polyedre
 * 
 */
void delete_polyedre(Polyedre &poly3d);





/*! \struct test
 * \author Paul BERNARD
 * \version 0.1
 * \brief classe test
 *
 */
typedef struct test
{
  int numface;/*!< num d'une face*/
  Point3d* tabpt;/*!< tab des points de la face*/
  double baryc;/*!< barycentre de la face*/
}test;

  






#endif
