
/*! \file classetriangleisocele.hh
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classetriangleisocele.hh
 * \brief classe de triangle isocele
*/

#ifndef __CLASSETRIANGLEISOCELE_HH_
#define __CLASSETRIANGLEISOCELE_HH_



#include "include.hh"
#include "classetriangle.hh"


/*! \class TriangleIsocele
 * \author Paul BERNARD
 * \version 0.1
 * \brief classe triangleIsocele
 *
 */

class TriangleIsocele : public Triangle {
  
public:
  
  /*! 
   * \fn TriangleIsocele (void) 
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * \brief Constructeur de la class triangleIsocele
   */ 
  TriangleIsocele(void);
  
  /*! 
   * \fn ~TriangleIsocele (void) 
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * \brief Destructeur de la class triangleIsocele
   */ 
  ~TriangleIsocele(void);
  
  
  /*! \fn TriangleIsocele(const TriangleIsocele &tri_iso) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &tri_iso : un triangleIsocele
   * 
   * \brief constructeur par copie d'un triangleIsocele
   * 
   * 
   */ 
  TriangleIsocele(const TriangleIsocele  &triangleIsocele);


 /*! \fn TriangleIsocele& operator=(const TriangleIsocele &tri_iso) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &tri_iso : un triangleIsocele
   * 
   * \return la copie du triangleIsocele
   * 
   * \brief permet d'effectuer une copie par affectation
   * 
   * 
   */ 
  TriangleIsocele& operator=(const TriangleIsocele &tri_iso);


  /*! \fn TriangleIsocele(bool &etat) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &etat : etat du triangle (true si isocele sinon false)
   * 
   * \brief constructeur d'un triangleIsocele
   * 
   * 
   */ 
  TriangleIsocele(bool &etat);

 
};

  



#endif
