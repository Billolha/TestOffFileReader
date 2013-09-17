
/*! \file classepolygonne.hh
 *
 * \author Paul BERNARD <paul.bernard@eisti.fr>
 *                                                   
 * \version 0.1
 *            Creation du fichier classepolygonne.hh
 * \brief classe de polygonnz
*/

#ifndef __CLASSEPOLYGONNE_HH_
#define __CLASSEPOLYGONNE_HH_


#include "include.hh"
#include "classepoint.hh"
#include "classevecteur.hh"
#include "classeobjet2d.hh"



#include "ZoneAffichage.hh"

/*! \class Polygonne
 * \author Paul BERNARD
 * \version 0.1
 * \brief classe polygonne
 *
 */
class Polygonne : public Objet2d
{
protected :
  int nbSommet;/*!< nb de sommet du polygonne*/
  Point* tabP;/*!< tab des points du polygonne*/
  float inciloin;/*!< incidence loin*/
  int ptloin;/*!< point loin*/
  int ptpres;/*!< point pres*/
  float incipres;/*!< incidence de pres*/
public :
  /*! \fn  Polygonne(void) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \brief permet d'init un polygonne par defaut
   * 
   */ 
  Polygonne(void);
  

  /*! \fn  Polygonne(int nb) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param nb : le nb de sommets
   * 
   * \brief permet d'init un polygonne
   * 
   * 
   */ 
  Polygonne(int nb);

   /*! \fn void Polygonne(const Polygonne &pol) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * \version 0.2 
   *           Gestion des exceptions
   * 
   * \param &pol : un polygonne
   * 
   * \brief constructeur par copie d'un polygonne
   * 
   * \remarks peut lever une exception
   */ 
  Polygonne(const Polygonne &pol);
 
  /*! \fn Polygonne& operator=(const Polygonne &pol) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &pol : un polygonne
   * 
   * \return la copie du polygonne
   * 
   * \brief permet d'effectuer une copie par affectation
   * 
   * 
   */ 
  Polygonne& operator=(const Polygonne &pol);

  /*! \fn void liberer(void) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \brief permet de liberer le tab de Points de taille nbSommet
   * 
   * 
   */ 
  void liberer(void);
   
  /*! \fn void affichage(void) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \brief permet d'afficher les coord des points du polygonne
   * 
   * 
   */ 
  void affichage(void) const; 

  /*! \fn void affichage(ZoneAffichage* zoneAffichage)
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param zoneAffichage : la zoneAffichage
   * 
   * \brief permet d'afficher les objets
   * 
   */ 
  void affichage(ZoneAffichage* zoneAffichage);
  
  
  
  /*! \fn void translate(Vecteur vect) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param vect : le vecteur de deplacement
   * 
   * \brief permet de translater un polygonne suivant le vecteur en param
   * 
   * 
   */ 
  void translate(Vecteur vect);
  
  /*! \fn void symetrie_cent(const Point &pt) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param pt : le point de rapport
   * 
   * \brief permet de realiser la symetrie centrale du polygone par rapport a pt
   * 
   * 
   */ 
  void symetrie_cent(const Point &pt);
  
  /*! \fn void homothetie(const Point &pt, float k) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param pt : le point de rapport
   * \param k : rapport
   * 
   * \brief permet de afire une homothetie du polygonne par rapport a pt de rapport k
   * 
   * 
   */ 
  void homothetie(const Point &pt, float k);
  
  /*! \fn  ~Polygonne(void) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \brief destructeur de polygonne
   * 
   * 
   */ 
  ~Polygonne(void);

  /*! \fn float perimetre(void) const 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * \version 0.2 
   *           Gestion des exceptions
   * 
   * 
   * \return le perimettre du polygonne
   * 
   * \brief permet de calculer le perimetre du polygonne
   * 
   * \remarks peut lever une exception
   */ 
  float perimetre(void) const;
 
  /*! \fn void lire_polygonne_binaire(char* fichier) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * \version 0.2 
   *           Gestion des exceptions
   * \version 0.3 
   *           Gestion pour objet2d en virtual , changement de nom  
   * 
   * \param fichier : le nom du fichier
   * 
   *
   * \brief permet d'affecter les points d'un polygonne a partir d'un fichier
   * 
   * \remarks utilise la fonction lire_Point, peut lever une exception 
   */ 
  void lire_polygonne_binaire(char* fichier);

  /*! \fn void ecrire_polygonne_binaire(char* fichier) const 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * \version 0.2 
   *           Gestion des exceptions
   * 
   * \param fichier : le nom du fichier
   * 
   * 
   * \brief permet d'ecrire les points d'un polygonne dans un fichier
   * 
   * \remarks utilise la fonction ecrire_Point, peut lever une exception 
   */ 
  void ecrire_polygonne_binaire(char* fichier) const;


  /*! \fn float virtual aire(void) const
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * 
   * \return l'aire du polygonne
   * 
   * \brief permet de calculer l'aire du polygonne
   * 
   *\remarks methode virtuelle
   * 
   */ 
  virtual float aire(void) const;
  

  /*! 
   * \fn int  get_nb_sommet(void) const ;
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * 
   * \return retourne le champ nbSommet 
   * 
   * \brief Accesseur en lecture a la variable nbSommet
   */ 
  int get_nb_sommet(void) const ;

  /*! 
   * \fn Point*  get_tab_pts(void) const ;
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * 
   * \return retourne le tab de points
   * 
   * \brief Accesseur en lecture au tab de points
   */ 
  Point* get_tab_pts(void) const ;


  /*! \fn void modifPoint(int pos, float abs, float ord) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * \version 0.2 
   *           Gestion des exceptions
   * 
   * \param pos : position su point dans le polygonne
   * \param abs : abcisse du point
   * \param ord : ordonnee du point
   * 
   * \brief permet de modifier un point d'un polygonne
   * 
   * \remarks peut lever une exception
   */ 
  void modifPoint(int pos,float abs,float ord);
  

  /*! \fn void modifPoint(Point* &p) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param p : un point
   * 
   * \brief permet de modifier un point
   * 
   */ 
  void modifPoint(Point* &p);


  /*! \fn void set_nb_sommet(int nb) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param nb : un nombre
   * 
   * \brief permet de definir le nb de sommets
   * 
   */ 
  void set_nb_sommet(int nb) ; 
  
  /*! \fn void set_inciloin(float nb) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param nb : un nombre
   * 
   * \brief permet de definir l'incidence de loin
   * 
   */ 
  void set_inciloin(float nb);

  /*! \fn void set_incipres(float nb) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param nb : un nombre
   * 
   * \brief permet de definir l'incidence de pres
   * 
   */ 
  void set_incipres(float nb);

  /*! \fn void set_ptloin(int nb) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param nb : un nombre
   * 
   * \brief permet de definir le pt loin
   * 
   */ 
  void set_ptloin(int nb);

  /*! \fn void set_ptpres(int nb) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param nb : un nombre
   * 
   * \brief permet de definir le pt pres
   * 
   */ 
  void set_ptpres(int nb);
  
  /*! 
   * \fn float  get_inciloin(void) const ;
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * 
   * \return retourne l'incidence de loin 
   * 
   * \brief Accesseur en lecture a la variable inciloin
   */ 
  float get_inciloin(void) const;

  /*! 
   * \fn float  get_incipres(void) const ;
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * 
   * \return retourne l'incidence de pres 
   * 
   * \brief Accesseur en lecture a la variable incipres
   */ 
  float get_incipres(void) const;

  /*! 
   * \fn int  get_ptloin(void) const ;
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * 
   * \return retourne le pt loin 
   * 
   * \brief Accesseur en lecture a la variable ptloin
   */ 
  int get_ptloin(void) const;

  /*! 
   * \fn int  get_ptpres(void) const ;
   * \author Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   * 
   * \return retourne le pt pres 
   * 
   * \brief Accesseur en lecture a la variable ptpres
   */ 
  int get_ptpres(void) const;
  
};


#endif
