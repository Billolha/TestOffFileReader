
/*! \file classetrianglerectangle.hh
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classetrianglerectangle.hh
 * \brief classe de triangle rectangle
*/

#ifndef __CLASSETRIANGLERECTANGLE_HH_
#define __CLASSETRIANGLERECTANGLE_HH_



#include "include.hh"
#include "classetriangle.hh"


/*! \class TriangleRectangle
 * \author Paul BERNARD
 * \version 0.1
 * \brief classe triangleRectangle
 *
 */

class TriangleRectangle : public Triangle {
  
public:
  
  /*! 
   * \fn TriangleRectangle (void) 
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * \brief Constructeur de la class triangleRectangle
   */ 
  TriangleRectangle(void);
  
  /*! 
   * \fn ~TriangleRectangle (void) 
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * \brief Destructeur de la class triangleRectangle
   */ 
  ~TriangleRectangle(void);
  
  
  /*! \fn TriangleRectangle(const TriangleRectangle &tri_rect) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &tri_rect : un triangleRectangle
   * 
   * \brief constructeur par copie d'un triangleRectangle
   * 
   * 
   */ 
  TriangleRectangle(const TriangleRectangle  &triangleRectangle);


 /*! \fn TriangleRectangle& operator=(const TriangleRectangle &tri_rect) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &tri_rect : un triangleRectangle
   * 
   * \return la copie du triangleRectangle
   * 
   * \brief permet d'effectuer une copie par affectation
   * 
   * 
   */ 
  TriangleRectangle& operator=(const TriangleRectangle &tri_rect);


  

  /*! \fn TriangleRectangle(bool &etat) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &etat : etat du triangle (true si rectangle sinon false)
   * 
   * \brief constructeur d'un triangleRectangle
   * 
   * 
   */ 
  TriangleRectangle(bool &etat);

 
};

  



#endif
