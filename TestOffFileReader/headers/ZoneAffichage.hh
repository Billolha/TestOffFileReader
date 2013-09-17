#ifndef ZONEAFFICHAGE_H
#define ZONEAFFICHAGE_H

#include "include.hh"
#include <QWidget>
#include "classeobjet2d.hh"
#include "classepolygonne.hh"



class Polygonne;


/*! 
 * \fn Polygonne* to2d3d(Polyedre* &poly3d) 
 * \author  Paul BERNARD <paul.bernard@eisti.fr> 
 * \version 0.1 
 *          Création de la fonction
 * 
 * \param &poly3d : un polyedre
 * 
 * \return un pointeur sur polygonnes
 * 
 * \brief permet de transformer le polyedre en polygonnes
 * 
 * 
*/ 
Polygonne*  to2d3d ( Polyedre* & poly3d);


/*! 
 * \fn void rotatepolyedrey(Polyedre &poly3d, double phi) 
 * \author  Paul BERNARD <paul.bernard@eisti.fr> 
 * \version 0.1 
 *          Création de la fonction
 * 
 * \param &poly3d : un polyedre
 * \param phi : un angle
 * 
 * \brief permet de faire tourner le polyedre selon y
 * 
 * 
*/ 
void rotatepolyedrey (Polyedre & poly3d,double phi);

/*! 
 * \fn void rotatepolyedrex(Polyedre &poly3d, double alpha) 
 * \author  Paul BERNARD <paul.bernard@eisti.fr> 
 * \version 0.1 
 *          Création de la fonction
 * 
 * \param &poly3d : un polyedre
 * \param alpha : un angle
 * 
 * \brief permet de faire tourner le polyedre selon x
 * 
 * 
*/ 
void rotatepolyedrex (Polyedre & poly3d,double alpha);

/*! 
 * \fn void tripolyedre(Polyedre &poly3d) 
 * \author  Paul BERNARD <paul.bernard@eisti.fr> 
 * \version 0.1 
 *          Création de la fonction
 * 
 * \param &poly3d : un polyedre
 * 
 * \brief permet de trier le polyedre
 * 
 * 
*/ 
void tripolyedre (Polyedre & poly3d );

/*! 
 * \fn void tripolyedre2(Polyedre &poly3d) 
 * \author  Paul BERNARD <paul.bernard@eisti.fr> 
 * \version 0.1 
 *          Création de la fonction
 * 
 * \param &poly3d : un polyedre
 * 
 * \brief permet de trier le polyedre
 * 
 * 
*/ 
void tripolyedre2 (Polyedre & poly3d );


/*! 
 * \fn Polyedre* backfaceculling(Polyedre &poly3d) 
 * \author  Paul BERNARD <paul.bernard@eisti.fr> 
 * \version 0.1 
 *          Création de la fonction
 * 
 * \param &poly3d : un polyedre
 * 
 * \return le polyedre
 * 
 * \brief permet de supprimer les faces invisibles
 * 
 * 
*/ 
Polyedre * backfaceculling (Polyedre & poly3d) ;



/*! 
 * \fn void zoompoly(Polyedre &poly3d, double z) 
 * \author  Paul BERNARD <paul.bernard@eisti.fr> 
 * \version 0.1 
 *          Création de la fonction
 * 
 * \param &poly3d : un polyedre
 * \param z : un coeficient
 * 
 * \brief permet de zoomer ou dezoomer sur le polyedre
 * 
 * 
*/ 
void zoompoly (Polyedre & poly3d, double z) ;

/*! 
 * \fn void movepoly(Polyedre &poly3d, double x, double y) 
 * \author  Paul BERNARD <paul.bernard@eisti.fr> 
 * \version 0.1 
 *          Création de la fonction
 * 
 * \param &poly3d : un polyedre
 * \param x : un coefficient
 * \param y : un coefficient
 * 
 * \brief permet de deplace le polyedre
 * 
 * 
*/ 
void movepoly (Polyedre & poly3d, double x, double y);



/*! \class ZoneAffichage
 * \author Paul BERNARD
 * \version 0.1
 * \brief classe ZoneAffichage
 *
 */

class ZoneAffichage : public QWidget
{
 protected:
  Objet2d** ttobj2d;/*!< tableau d'objet*/ 
  int my_taille;/*!< la taille */ 
  Polyedre  poly3d;/*!< un polyedre */ 
  
  
  /*! \fn  void paintEvent(QPaintEvent* event) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * \param event : un paint event
   * 
   * \brief permet de colorier 
   * 
   */ 
  void paintEvent(QPaintEvent *event);

 public:

  /*! \fn  void set_taille(int t) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * \param t : la taille 
   * 
   * \brief permet de definir la taille 
   * 
   */ 
  void set_taille(int t);

  /*! \fn  void set_poly(Polyedre &polyedre3D) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * \param polyedre3D : un polyedre 
   * 
   * \brief permet de definir le polyedre 
   * 
   */ 
  void set_poly(Polyedre &polyedre3D);

  /*! \fn  void set_ttobj(Objet2d** &param) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * \param param : un tableau d'objet
   * 
   * \brief permet de definir le tableau d'objet  
   * 
   */ 
  void set_ttobj(Objet2d** &param);

  /*! 
   * \fn  ZoneAffichage(QWidget* parent = 0) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *          Création de la fonction
   * 
   * \param parent = 0 : son parent
   * 
   * \brief constructeur de la zone affichage
   * 
   * 
   */ 
  ZoneAffichage(QWidget *parent = 0);

   /*! \fn  void rotatezay(float phi) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * \param phi : un angle
   * 
   * \brief permet de faire une rotation selon y 
   * 
   */ 
  void rotatezay(float phi);

   /*! \fn  void rotatezax(float alpha) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * \param alpha : un angle
   * 
   * \brief permet de faire une rotation selon x 
   * 
   */ 
  void rotatezax(float alpha);

   /*! \fn  QSize minimumSizeHint() const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * \return : une QSize
   * 
   * \brief permet de definir la taille minimale de la fenetre 
   * 
   */ 
  QSize minimumSizeHint() const;

   /*! \fn  QSize sizeHint() const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * \return : une QSize
   * 
   * \brief permet de definir la taille initiale de la fenetre 
   * 
   */ 
  QSize sizeHint() const;

  /*! \fn  void zoom(double z) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * \param z : un coeficient
   * 
   * \brief permet de faire un zoom selon le coeficient
   * 
   */ 
  void zoom (double z);
  
  /*! \fn  void move(double x,double y) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   *
   * \param x : un coeficient
   * \param y : un coeficient
   * 
   * \brief permet de faire deplacer la piece
   * 
   */ 
  void move (double x, double y);
  
};



#endif
