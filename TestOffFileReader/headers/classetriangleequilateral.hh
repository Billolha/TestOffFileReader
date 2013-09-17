
/*! \file classetriangleequilateral.hh
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classetriangleequilateral.hh
 * \brief classe de triangle equilateral
*/

#ifndef __CLASSETRIANGLEEQUILATERAL_HH_
#define __CLASSETRIANGLEEQUILATERAL_HH_



#include "include.hh"
#include "classetriangle.hh"


/*! \class TriangleEquilateral
 * \author Paul BERNARD
 * \version 0.1
 * \brief classe triangleEquilateral
 *
 */

class TriangleEquilateral : public Triangle {
  
public:
  
  /*! 
   * \fn TriangleEquilateral (void) 
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * \brief Constructeur de la class triangleEquilateral
   */ 
  TriangleEquilateral(void);
  
  /*! 
   * \fn ~TriangleEquilateral (void) 
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * \brief Destructeur de la class triangleEquilateral
   */ 
  ~TriangleEquilateral(void);
  
  
  /*! \fn TriangleEquilateral(const TriangleEquilateral &tri_equi) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &tri_equi : un triangleEquilateral
   * 
   * \brief constructeur par copie d'un triangleEquilateral
   * 
   * 
   */ 
  TriangleEquilateral(const TriangleEquilateral  &triangleEquilateral);


 /*! \fn TriangleEquilateral& operator=(const TriangleEquilateral &tri_equi) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &tri_equi : un triangleEquilateral
   * 
   * \return la copie du triangleEquilateral
   * 
   * \brief permet d'effectuer une copie par affectation
   * 
   * 
   */ 
  TriangleEquilateral& operator=(const TriangleEquilateral &tri_equi);

  

  /*! \fn TriangleEquilateral(bool &etat) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &etat : etat du triangle (true si equilateral sinon false)
   * 
   * \brief constructeur d'un triangleEquilateral
   * 
   * 
   */ 
  TriangleEquilateral(bool &etat);

 
 
};

  



#endif
