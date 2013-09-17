/*
 *      tmp.cc
 *      
 *      Copyright 2008 William Olhasque <william.olhasque <at> gmail <dot> com>
 *      
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *      
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *      
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */
#ifndef __TMP_HH__
#define __TMP_HH__

#include "include.hh"
#include "main.hh"




//#include "classepoint.hh"



/*! \fn bool operator<(const test& t1,const test& t2) 
 * \author  Paul BERNARD <paul.bernard@eisti.fr> 
 * \version 0.1 
 *           Creation de la fonction
 * 
 * \param t1 : le premier
 * \param t2 : le deuxieme
 *
 * \return vrai si le premier est plus petit que le second
 *
 * \brief peremet de definir test comme un ensemble ordonnee
 *
 * \remarks necessaire pour utiliser le sort de STL
 *
 */
bool operator<(const test& t1, const test& t2);

bool operator<(const test& t1, const test& t2) {
  return (t1.baryc < t2.baryc);
}




/*! \class Point3d
 * \author Paul BERNARD
 * \version 0.1
 * \brief classe Point3d
 *
 */
class Point3d : public Point {
protected:
  double my_dz;/*!< profondeur */
public :

  /*! \fn  Point3d(void) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \brief permet d'init un point3d par defaut
   * 
   */ 
  Point3d(void);
  
  /*! \fn  Point3d(double x, double y, double z) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param x : l'abcisse
   * \param y : l'ordonnee
   * \param z : la profondeur
   *
   * \brief permet d'init un point3d par valeur
   * 
   */ 
  Point3d(double x,double y,double z);

  /*! \fn Point threetotwoiso(void) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \return nu point
   * 
   * \brief permet de calculer point 2d par iso
   * 
   */ 
  Point threetotwoiso (void);	
  
  /*! \fn Point threetotwoortho(void) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \return nu point
   * 
   * \brief permet de calculer point 2d par ortho
   * 
   */ 
  Point threetotwoortho (void);

  /*! \fn Point3d& operator=(const Point3d &p) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param &p : un point3d
   * 
   * \return la copie du point3d
   * 
   * \brief permet d'effectuer une copie par affectation
   * 
   * 
   */ 
  Point3d& operator=(const Point3d &p);

  /*! \fn void setdx(double x) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param x : abcisse
   * 
   * \brief permet d'affecter l'abcisse
   * 
   */ 
  void setdx(double x);

  /*! \fn void setdy(double y) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param y : ordonnee
   * 
   * \brief permet d'affecter l'ordonnee
   * 
   */ 
  void setdy(double y);

  /*! \fn void setdz(double z) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param z : profondeur
   * 
   * \brief permet d'affecter la profondeur
   * 
   */ 
  void setdz(double z);


  /*! \fn void affiche()
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \brief permet d'afficher
   * 
   */ 
  void affiche();

  
  /*! \fn double getz()
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \return la profondeur
   *
   * \brief permet de retourner la profondeur
   * 
   */ 
  double getz();

  /*! \fn double getx()
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \return la abcisse
   *
   * \brief permet de retourner la abcisse
   * 
   */ 
  double getx();

  /*! \fn double gety()
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \return la ordonnee
   *
   * \brief permet de retourner la ordonnee
   * 
   */ 
  double gety();

  /*! \fn void rotatey(double phi) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param phi : un angle
   * 
   * \brief permet d'effectuer une rotation selon y
   * 
   */ 
  void rotatey(double phi);


  /*! \fn void zoom(double z) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param z : la profondeur
   * 
   * \brief permet d'effectuer un zoom ou dezoom
   * 
   */ 
  void zoom (double z) ;

  /*! \fn void rotatex(double alpha) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param alpha : un angle
   * 
   * \brief permet d'effectuer une rotation selon x
   * 
   */ 
  void rotatex(double alpha);
  
  
    /*! \fn void move(double x,double y) 
   * \author  Paul BERNARD <paul.bernard@eisti.fr> 
   * \version 0.1 
   *           Creation de la fonction
   * 
   * \param x : une coordonnée
   * \param y : une coordonnée
   * 
   * \brief permet de déplacer le point
   * 
   */ 
  void move(double x, double y); 
};



Point3d::Point3d(void) {
	//Constructeur par defau
  my_dz = 0.0;
}

Point3d::Point3d(double x,double y,double z) : Point(x,y) {
	//Constructeur a partir d'un point donne
  my_dz = z;
}

Point Point3d::threetotwoiso (void) {
  Point tmp(((sqrt(2)/2)*(my_dx-my_dy))+200,
  			(sqrt(2/3)*my_dz)-(1/sqrt(6))*(my_dx+my_dy)+200);
  			//Transformation 3d -> 2d en 3d isometrique
  return(tmp);
}


void Point3d::move(double x, double y) {
	//Deplace le point de x et de y
	my_dx = my_dx +x;
	my_dy = my_dy +y;
}


Point Point3d::threetotwoortho (void) {
  Point tmp(my_dx+400,my_dy+300);
  //Transformation 3d -> 2d en 3d orthogonale
  return(tmp);
}

void Point3d::setdx(double x){
	//Affectation du x
	my_dx=x;
}

void Point3d::setdy(double y){
	//Affectation du 
	my_dy=y;
}

void Point3d::setdz(double z){
	//Affectation du z
	my_dz=z;
}

double Point3d::getz() {
	//retourne le z
  return(my_dz);
}
double Point3d::getx() {
	//retourne le x
  return(my_dx);
}
double Point3d::gety() {
	//retourne le y
  return(my_dy);
}



void Point3d::zoom (double z) {
	//On zoome le point
	my_dx= my_dx * z;
	my_dy= my_dy * z;
	my_dz=my_dz *z;
	
}

Point3d& Point3d::operator=(const Point3d &p)
{
  //si l'objet n'est pas le meme 
  if(this!= &p){
    //on copie les champs un par un
    my_dx = p.my_dx;
    my_dy = p.my_dy;
    my_dz = p.my_dz;
  }
  //on retourne l'objet
  return(*this);
}


/*! \fn Point3d barycentre(Point3d*& ttab, int nbpts) 
 * \author  Paul BERNARD <paul.bernard@eisti.fr> 
 * \version 0.1 
 *           Creation de la fonction
 * 
 * \param &ttab : tab de point3d
 * \param nbpts : nb de point3d
 * 
 * \return le barycentre de touts les point3d
 * 
 * \brief permet de trouver le barycentre des point3d
 * 
 * 
*/ 
Point3d barycentre(Point3d *& ttab, int nbpts)
{
  Point3d baryc(0,0,0);
  int i;
  
  for(i=0 ; i<nbpts ; i++){
	
    baryc.setdz(baryc.getz() + ttab[i].getz());
  }
	//On ne calcul le z barycentre du barycentre c'est le seul qui nous sert
   baryc.setdx(baryc.getz() / nbpts);
    
   return(baryc);
   
}

void Point3d::affiche() {
	//Affichage des coordonnées d'un point 3d
	cout << "x = " << my_dx << " y = " << my_dy << " z = " << my_dz << endl;
}

void Point3d::rotatey(double phi){
	//Ontour selon l'angle phi autour de l'axe y  
		double tmpx;
		double tmpz;
		tmpx = my_dx;
		tmpz = my_dz;
		my_dx = (tmpx*cos(phi)+tmpz*sin(phi));
		my_dz = (-tmpx*sin(phi)+tmpz*cos(phi));
		
		
}

void Point3d::rotatex(double alpha){
	//Ontour selon l'angle phi autour de l'axe x  
		double tmpy;
		double tmpz;
		tmpy = my_dy;
		tmpz = my_dz;
		my_dy = (tmpy*cos(alpha)+tmpz*sin(alpha));
		my_dz = (-tmpy*sin(alpha)+tmpz*cos(alpha));
}



void rotatepolyedrey (Polyedre & poly3d,double phi) {

	int i,j;
	for (i=0; i<poly3d.nbface; i++) {
		for (j = 0 ; j < poly3d.nbpointbyface[i]; j++ ) {
			//On fait tourner chaque point de chaque face
			(poly3d.ttabpts3d[i][j]).rotatey(phi);
		}
	}
}

void rotatepolyedrex (Polyedre & poly3d,double alpha) {

	int i,j;
	for (i=0; i<poly3d.nbface; i++) {
		for (j = 0 ; j < poly3d.nbpointbyface[i]; j++ ) {
			//On fait tourner chaque point de chaque face
			(poly3d.ttabpts3d[i][j]).rotatex(alpha);
		}
	}
}

void movepoly (Polyedre & poly3d, double x, double y) {
	int i,j;
	for (i=0; i<poly3d.nbface; i++) {
		for (j = 0 ; j < poly3d.nbpointbyface[i]; j++ ) {
			//On fait tourner chaque point de chaque face
			(poly3d.ttabpts3d[i][j]).move(x,y);
		}
	}
	
}


void zoompoly (Polyedre & poly3d, double z) {
  int i,j;
  for (i=0; i<poly3d.nbface; i++) {
    for (j = 0 ; j < poly3d.nbpointbyface[i]; j++ ) {
    	//On zoom chaque point de chaque face
      (poly3d.ttabpts3d[i][j]).zoom(z);
    }
  }
}


/*! \fn Point3d incidence(Point3d*& pt3d, int nbpoint) 
 * \author  Paul BERNARD <paul.bernard@eisti.fr> 
 * \version 0.1 
 *           Creation de la fonction
 * 
 * \param pt3d : point3d
 * \param nbpoint : nb de point3d
 * 
 * \return l'incidence
 * 
 * \brief permet de trouver l'incidence
 * 
 * 
*/ 
double incidence (Point3d * & pt3d,int nbpoint) {	
//Retourne l'incidence du point par rapport au plan xOy
return((pt3d[nbpoint-1].getx() - pt3d[1].getx())*(pt3d[0].gety()-pt3d[1].gety())-(pt3d[0].getx()-pt3d[1].getx())*(pt3d[nbpoint-1].gety() - pt3d[1].gety()))	;
	
}


Polyedre * backfaceculling (Polyedre & poly3d) {
	Polyedre * poly3dtmp;
	poly3dtmp = new Polyedre;
	int i,j;


	j = 0;
	//On recherche toute les faces que l'utilisateur  voit  cad dont l'incidence est sup a 0
	for (i=0; i < poly3d.nbface;i++) {
		if ( incidence(poly3d.ttabpts3d[i],poly3d.nbpointbyface[i]) >= 0 ) {
			j++;		
		}
	}
	//On creer un nouvo polydedre dont les face sont vu
	poly3dtmp->nbface = j;
	poly3dtmp->nbpointbyface = new int[j];
	poly3dtmp->ttabpts3d = new Point3d*[j];
	
	j=0;
	//On copie les face vu dans le nouvo polyedre
	for (i = 0 ; i < poly3d.nbface ; i++ ) {
		if ( incidence(poly3d.ttabpts3d[i],poly3d.nbpointbyface[i]) >= 0 ) {
			poly3dtmp->ttabpts3d[j] = new Point3d[poly3d.nbpointbyface[i]];	
			poly3dtmp->ttabpts3d[j] = poly3d.ttabpts3d[i];
			poly3dtmp->nbpointbyface[j] = poly3d.nbpointbyface[i];
			j++;
		}
		
	}
	
	return(poly3dtmp);
}


//TRI BOURRIN
void tripolyedre (Polyedre & poly3d ) {
	int k, i, j,nbtmp ;
	vector<double> v;
	Point3d * facetmp;
	
	for (k=0;k<poly3d.nbface;k++){
		v.push_back(barycentre(poly3d.ttabpts3d[k],poly3d.nbpointbyface[k]).getz());
	}
	//On range le vecteur
	sort(v.begin(),v.end());
	
	for (k=0;k<poly3d.nbface;k++) {
		i=0;
		while (v[k] != barycentre(poly3d.ttabpts3d[i],poly3d.nbpointbyface[i]).getz()){
			i++;
		}
		if (i != k) {
			nbtmp = poly3d.nbpointbyface[i];
			facetmp = new Point3d[nbtmp];
			for (j = 0 ; j < nbtmp ; j++) {
			  facetmp[j] = poly3d.ttabpts3d[i][j];
			}
			for (j=0;j <  poly3d.nbpointbyface[k]; j++){
			  poly3d.ttabpts3d[i][j] = poly3d.ttabpts3d[k][j];
			}
			poly3d.nbpointbyface[i] = poly3d.nbpointbyface[k];
			poly3d.nbpointbyface[k] = nbtmp;
			for (j = 0 ; j < nbtmp ; j++) {
			  poly3d.ttabpts3d[k][j] =	facetmp[j];
			}	
			delete [] facetmp;
			
		}
		
	}
}


//TRI UN PEU MOINS BOURRIN
void tripolyedre2 (Polyedre & poly3d ) {
  int i;
  vector<test> v;
  test t;
  
  for (i=0 ; i<poly3d.nbface ; i++){
    t.numface = poly3d.nbpointbyface[i];
    t.tabpt = poly3d.ttabpts3d[i];
    t.baryc = (barycentre(poly3d.ttabpts3d[i],poly3d.nbpointbyface[i]).getz());
    v.push_back(t);
  }

  //on recup la taille du vecteur
  int taille = v.size();

  //On range le vecteur
  sort(v.begin(),v.end());

    
  //on 
  for (i = 0 ; i < taille ; i++ ){
    poly3d.ttabpts3d[i] = v[i].tabpt;
    poly3d.nbpointbyface[i] = v[i].numface;
  }
}


Polyedre chargeficoff (const char * nomfic) {
	FILE* f;
	double x,y,z;
	Polyedre poly3d;
  	char c[3];
	int nbsommet, nbface, nbarretes, nb, i, j;
	Point3d* pts3d;
	Point3d tmp,bar;
	
	
	j=0;
	
	//Ouverture du fichier	
  	f = fopen(nomfic, "r"); 
  	
	//On lit les trois premier charactere (OFF)
 	fread(c, sizeof(char), 3, f);
 	
 	//Lecture nbsommet nbface nbarretes
 	fscanf(f,"%d",&nbsommet);
 	fscanf(f,"%d",&nbface);
 	fscanf(f,"%d",&nbarretes);
 	
	//On alloue la mémoire pour les point 3d et 2d
	pts3d = new Point3d[nbsommet];
	poly3d.ttabpts3d = new Point3d*[nbface];
	poly3d.nbface = nbface;
	poly3d.nbpointbyface = new int[nbface];
	
	
	//Tant qu'on a pas recuperer toutes les infos contenant les points
  	for (i=0;i<nbsommet;i++) {
  		//On lit les donnees concernant les points
    	fscanf (f,"%lf",&x);
    	fscanf (f,"%lf",&y);
    	fscanf (f,"%lf",&z);
    	//On cree un point 3d suivant ces points
    	Point3d tmp(x*40,y*40,z*40);
    	//On ajoute le point 3d dans le tableau de point 3d
    	pts3d[i] = tmp;
  	}
	

 	//Tant qu'on a pas recuperer les infos sur toutes les faces
  	while (j != nbface){
	  //On lit le nbr de point compris dans cette face
	  fscanf (f,"%d",&nb);
	  //On alloue un tab de point  2d et 3d 
	  
	  poly3d.ttabpts3d[j] = new Point3d[nb];
	  
	  //Tant qu'on a pas toutes les infos sur les poitns de la face
	  for (i = 0 ; i<nb; i++) {
	    int tmp2;
	    //On lit quel point appartient a celle ci
	    fscanf (f,"%d",&tmp2);
	    //On cree un tab 2d et 3d des points de la face
	    poly3d.ttabpts3d[j][i]  = pts3d[tmp2];
	  }
	  
	  poly3d.nbpointbyface[j] = nb;
	  //Face suivante
	  j++;
  	}	
  	fclose(f);
  	
  	
  	//On supprime le tab de poitn 3d

  	delete[] pts3d;
  	return(poly3d);
}



/*! \fn Polygonne transforme3d2d(Point3d*& tabpts3d, int nbpoint) 
 * \author  Paul BERNARD <paul.bernard@eisti.fr> 
 * \version 0.1 
 *           Creation de la fonction
 * 
 * \param tabpts3d : tab de point3d
 * \param nbpoint : nb de point3d
 * 
 * \return un polygonne
 * 
 * \brief permet de transformer 3d vers 2d
 * 
 * 
*/ 
Polygonne transforme3d2d (Point3d*& tabpts3d,int nbpoint) {
	Polygonne  polytmp;
	double zloin,zpres,xloin,xpres,incilointmp,inciprestmp;
	int ptlointmp, ptprestmp,i;
	Point * tabpttmp;
	
	//On creer un polygonne de nbpoint
	tabpttmp = new Point[nbpoint];
	//On affecte ce nbpoint au nb de sommet du polygonne
	polytmp.set_nb_sommet(nbpoint);
	for ( i = 0 ;i < nbpoint ; i++) {
		Point3d tmp3d(tabpts3d[i].getx(),tabpts3d[i].gety(),tabpts3d[i].getz());
		tabpttmp[i] = tmp3d.threetotwoortho();
	}
	//On affecte le tab de point au polygonen
	polytmp.modifPoint(tabpttmp);	
	//Affecte et init des incidence et des point loin / pres
	zloin = tabpts3d[0].getz();
	zpres = tabpts3d[0].getz();
	xloin = tabpts3d[0].getx();
	xpres = tabpts3d[0].getx();
	ptlointmp = 0;
	ptprestmp = 0;
    for (i= 0 ; i< nbpoint ; i++) {
    	if (tabpts3d[i].getz() < zloin ){
    		zloin = tabpts3d[i].getz();	 
    		xloin = tabpts3d[i].getx();
    		ptlointmp = i;
    
    	}
    	if (tabpts3d[i].getz() > zpres ){
    		zpres = tabpts3d[i].getz();	
    		xpres = tabpts3d[i].getx();
    		ptprestmp = i;
    	}
    }
    
    
    incilointmp = atan(zloin/xloin)*180/3.14;
    inciprestmp = atan(zpres/xpres)*180/3.14;

	
	polytmp.set_inciloin(incilointmp);
	polytmp.set_incipres(inciprestmp);
	polytmp.set_ptloin(ptlointmp);
	polytmp.set_ptpres(ptprestmp);
	
return(polytmp);
}
 



Polygonne *  to2d3d ( Polyedre * & poly3d) {
  int i;
  
  Polygonne * poly2d = new Polygonne[poly3d->nbface];
  
  for (i = 0 ; i< poly3d->nbface ; i++) {
    //On cree des face suivant le polyedre
    poly2d[i] = transforme3d2d(poly3d->ttabpts3d[i],poly3d->nbpointbyface[i]);
    
  }
  return(poly2d);
}






void delete_polyedre(Polyedre &poly3d)
{
  int i;
  
//On nettoie toute les affectations
  if(poly3d.nbface > 0){
    
    if(poly3d.ttabpts3d != NULL){
     
      if(poly3d.nbpointbyface != NULL){
      	delete [] poly3d.nbpointbyface;
      }
      
      for (i=0 ; i<poly3d.nbface ; i++){
	delete [] poly3d.ttabpts3d[i];
      }
      delete [] poly3d.ttabpts3d;
    }
    
    poly3d.nbface = 0;
  }
  
}






#endif
