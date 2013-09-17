
/*! \file classevecteur.hh
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classevecteur.hh
 * \brief classe de vecteur
*/

#ifndef __CLASSEVECTEUR_HH_
#define __CLASSEVECTEUR_HH_


#include "include.hh"
#include "classepoint.hh"

class Vecteur
{private :
  float my_dx;
  float my_dy;
public :
  /*! \fn  Vecteur(void) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   *
   * \brief permet d'init un Vecteur aux valeurs par defaut
   * 
   * 
   */ 
  Vecteur(void);

  /*! \fn void Vecteur( float x, float y) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param x : valeur de l'abcisse
   * \param y : valeur de l'ordonne
   * 
   * \brief permet d'init un vecteur de composantes x et y
   * 
   * 
   */ 
  Vecteur(float x, float y);
  
  /*! \fn  Vecteur(const Point &A, const Point &B) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param A : un point
   * \param B : deuxieme point
   * 
   * 
   * \brief permet d'init un vecteur avec deux point
   * 
   * 
   */ 
  Vecteur(const Point &A, const Point &B);

  /*! \fn void Vecteur(const Vecteur &v) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &v : un vecteur
   * 
   * \brief constructeur par copie d'un vecteur
   * 
   * 
   */ 
  Vecteur(const Vecteur &p);
 
  /*! \fn Vecteur& operator=(const Vecteur &v) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &v : un vecteur
   * 
   * \return la copie du vecteur
   * 
   * \brief permet d'effectuer une copie par affectation
   * 
   * 
   */ 
  Vecteur& operator=(const Vecteur &p);



  /*! \fn  void vecteur_modif(const Point &A, const Point &B) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param A : un point
   * \param B : deuxieme point
   * 
   * 
   * \brief permet de recalculer un vecteur avec deux point
   * 
   * 
   */ 
  void vecteur_modif(const Point &A, const Point &B);
  
  /*! \fn void affichage(void) const 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \brief permet d'afficher les composantes d'un vecteur
   * 
   * 
   */ 
  void affichage(void) const; 
  
  /*! \fn void addition(const Vecteur &vect) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param vect : un vecteur
   * 
   * \brief permet l'addition du vecteur avec celui placé en param
   * 
   * 
   */   
  void addition(const Vecteur &vect);
  
  /*! \fn float norme(void) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \return la norme du vecteur
   * 
   * \brief permet de calculer la norme du vecteur
   * 
   * 
   */ 
  float norme(void) const;
  
  /*! \fn void normalise(void) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \brief permet de normaliser un vecteur
   * 
   * 
   */ 
  void normalise(void);
  
  /*! \fn void multiplie(float alpha) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param alpha : un scalaire
   * 
   * \brief permet de multiplier le vecteur par le scalaire alph
   * 
   * 
   */ 
  void multiplie(float alpha);
  
  /*! \fn float pdt_scalaire(const Vecteur &vect) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param vect : un vecteur
   * 
   * \return le pdt scalaire du vecteur avec vect
   * 
   * \brief permet de calculer le pdt scalaire par le vecteur placé en param
   * 
   * 
   */ 
  float pdt_scalaire(const Vecteur &vect) const;
  
  /*! \fn float abcisse(void) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \return l'abcisse du vecteur
   * 
   * \brief permet de retourner l'abcisse du vecteur
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
   * \brief permet de retourner l'ordonnee du vecteur
   * 
   * 
   */ 
  float ordonnee(void) const;

  /*! \fn  ~Vecteur(void) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \brief destructeur de vecteur
   * 
   * 
   */ 
  ~Vecteur(void);
  

  /*! \fn float produitScalaire1(Vecteur v) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param v : un vecteur
   * 
   * \return le produit scalaire des deux vecteurs
   * 
   * \brief permet de calculer le produit scalaire de deux vecteurs
   * 
   * 
   */ 
  float produitScalaire1(Vecteur v) const;

  /*! \fn float produitScalaire2(Vecteur &v) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &v : un vecteur
   * 
   * \return le produit scalaire des deux vecteurs
   * 
   * \brief permet de calculer le produit scalaire de deux vecteurs
   * 
   * 
   */ 
  float produitScalaire2(Vecteur &v) const;

  /*! \fn float produitScalaire3(const Vecteur &v) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &v : un vecteur
   * 
   * \return le produit scalaire des deux vecteurs
   * 
   * \brief permet de calculer le produit scalaire de deux vecteurs
   * 
   * 
   */ 
  float produitScalaire3(const Vecteur &v) const;

      
  /*! \fn bool operator==(const Vecteur &v) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param v : un vecteur
   * 
   * \return vrai si deux vecteur sont egaux sinon faux
   * 
   * \brief permet de faire un test d'égalité entre deux vecteur
   * 
   * 
   */ 
  bool operator==(const Vecteur &v) const;
  
    /*! \fn bool operator+(const Vecteur &v) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param v : un vecteur
   * 
   * \return la somme de deux vecteurs
   * 
   * \brief permet de faire la somme de deux vecteurs
   * 
   * 
   */ 
  Vecteur operator+(const Vecteur &v) const;

  /*! \fn Vecteur operator*(float lambda) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param lambda : un scalaire
   * 
   * \return le produit d'un vecteur par un scalaire
   * 
   * \brief permet de faire le produit externe d'un vecteur
   * 
   * 
   */ 
  Vecteur operator*(float lambda) const;
  
  
  /*! \fn Point operator+(const Point &p) const
 * \author  Paul BERNARD <paul.bernard@eisti.fr> 
 * \version 0.1 
 *           Creation de la fonction
 * 
 * 
 * \param &p : un point
 * 
 * \return la translation du point
 * 
 * \brief permet de faire la translation d'un point
 * 
 * 
 */ 
  Point operator+(const Point &p) const;
  


};


#endif
