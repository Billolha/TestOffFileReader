
/*! \file classepoint.hh
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classepoint.hh
 * \brief classe de point
*/

#ifndef __CLASSEPOINT_HH_
#define __CLASSEPOINT_HH_


#include "include.hh"




/*! \class Point
 * \author Paul BERNARD
 * \version 0.1
 * \brief classe Point
 *
 */
class Point
{protected :
  float my_dx;/*!< abcisse */  
  float my_dy;/*!< ordonne */  
  friend class Polygonne;  

public :
  
  /*! \fn  Point(void) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   *
   * \brief permet d'init un point aux valeurs par defaut
   * 
   * 
   */ 
  Point(void);
  
  /*! \fn void Point(float x, float y) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param x : valeur de l'abcisse
   * \param y : valeur de l'ordonne
   * 
   * \brief permet d'init un point au valeur x y
   * 
   * 
   */ 
  Point(float x, float y);

  /*! \fn void Point(const Point &p) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &p : un point
   * 
   * \brief constructeur par copie d'un point
   * 
   * 
   */ 
  Point(const Point &p);
 
  /*! \fn Point& operator=(const Point &p) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &p : un point
   * 
   * \return la copy du point
   * 
   * \brief permet d'effectuer une copy par affectation
   * 
   * 
   */ 
  Point& operator=(const Point &p);
   


  /*! \fn void affichage(void) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \brief permet d'afficher les coord d'un point
   * 
   * 
   */ 
  void affichage(void) const; 

  
  /*! \fn void translate(float x, float y) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param x : valeur de deplacement de l'abcisse
   * \param y : valeur de deplacement de l'ordonne
   * 
   * \brief permet de translater un point de +x +y  
   * 
   * 
   */  
  void translate(float x, float y);
  
  /*! \fn float distance(const Point &pt) const 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param pt : un point
   * 
   * \return la distnce entre le point de la fonction et celui en param
   * 
   * \brief permet de calculer la distance avec le point placé en param
   * 
   * 
   */   
  float distance(const Point &pt) const;
  
  /*! \fn float abcisse(void) const 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \return l'abcisse du point
   * 
   * \brief permet de retourner l'abcisse du point
   * 
   * 
   */ 
  float abcisse(void) const;
  
  /*! \fn float ordonnee(void) const 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \return l'ordonnee du point
   * 
   * \brief permet de retourner l'ordonnee du point
   * 
   * 
   */ 
  float ordonnee(void) const;

  /*! \fn  ~Point(void) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \brief destructeur de point
   * 
   * 
   */ 
  ~Point(void);
  
  /*! \fn void lire_Point_binaire(ifstream* fic) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * \version 0.2 
   *           Gestion des exceptions
   * 
   * \param fic : le descripteur du fichier
   *
   * 
   * \brief permet de lire un point dans un fichier
   * 
   * \remarks peut lever une exception
   */ 
  void lire_Point_binaire(ifstream* fic);
  
  
  /*! \fn void ecrire_Point_binaire(ofstream* fic) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * \version 0.2 
   *           Gestion des exceptions
   * 
   * \param fic : le descripteur du fichier
   * 
   * 
   * \brief permet d'ecrire un point dans un fichier
   * 
   * \remarks peut lever une exception
   * 
   */ 
  void ecrire_Point_binaire(ofstream* fic) const;



  /*! \fn bool operator==(const Point &pt) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param pt : un point
   * 
   * \return vrai si deux point sont egaux sinon faux
   * 
   * \brief permet de faire un test d'égalité entre deux point
   * 
   * 
   */ 
  bool operator==(const Point &pt) const;



  
  


};






#endif
