#include <QtGui>

#include "ZoneAffichage.hh"




ZoneAffichage::ZoneAffichage(QWidget *parent)
  :QWidget(parent)
{
} 


QSize ZoneAffichage::minimumSizeHint() const
    {
    	//Taille minimale
        return QSize(200, 200);
    }



QSize ZoneAffichage::sizeHint() const
    {
    	//Taille d'origine
        return QSize(1200, 1000);
    }



void ZoneAffichage::rotatezay(float phi) {
	Polygonne * poly2d;
	Polyedre * poly3d_2 = new Polyedre;
	//On fait tourner le polyedre
	rotatepolyedrey(poly3d,phi);	
	//On lance le backfaceculling
	poly3d_2 = backfaceculling(poly3d);
	//On recup le nbr de face du nouveau polyedre
	int nobface = poly3d_2->nbface;
	poly2d = new Polygonne[nobface];
	
	//On try le polyedre
	tripolyedre2(*poly3d_2);
	//On transforme le polyedre en plygone
	poly2d =to2d3d(poly3d_2);
		//On delete le tab d'objet 2d courant
	delete [] ttobj2d;
	//On en creer un nouveau
	ttobj2d = new Objet2d*[nobface];
	
	//On copie les polygone dans le tab d'objet 2d
	for(int i=0 ; i<nobface ; i++){  
		ttobj2d[i] = &poly2d[i];
	}
	//On change la taille du polygonne de la zone d'affichage
	my_taille = nobface;

//On supprime le polyedre tmp
	delete poly3d_2;	

}
void ZoneAffichage::rotatezax(float alpha) {
  /* VOIR COMMENTAIRE ROTATEZAY */
	Polygonne * poly2d;
	Polyedre * poly3d_2 = new Polyedre;
	rotatepolyedrex(poly3d,alpha);	
	poly3d_2 = backfaceculling(poly3d);
	int nobface = poly3d_2->nbface;
	poly2d = new Polygonne[nobface];
	tripolyedre2(*poly3d_2);
	poly2d =to2d3d(poly3d_2);
	delete [] ttobj2d;
	ttobj2d = new Objet2d*[nobface];
	for(int i=0 ; i<nobface ; i++){  
		ttobj2d[i] = &poly2d[i];
	}
	my_taille = nobface;
	delete poly3d_2;
}


void ZoneAffichage::paintEvent(QPaintEvent *)
{


  int i;
  for(i=0 ; i<my_taille ; i++){
    //si on a un objet a afficher
    if(ttobj2d[i] != NULL){
      //on l'affiche
      ttobj2d[i]->affichage(this);
      
    }
  }

 

}



void ZoneAffichage::set_poly(Polyedre& polyedre3D)
{
	//On affecte le polyedre a la zoneaffichage 
  poly3d = polyedre3D;
}


void ZoneAffichage::set_ttobj(Objet2d** &param)
{
  int i;
  //Si le tab d'objet n'est ps null
  if (param != NULL){
  	//Si on a un tab d'objet 2d de la ZA non null
    if(ttobj2d != NULL){
    	//On le delete
      delete [] ttobj2d;
    }
    //On le recreer
    ttobj2d =  new Objet2d*[my_taille];
    //On copie chaque case
    for(i=0 ; i<my_taille ; i++){  
      ttobj2d[i] = param[i];
    }
    
  }else{
  	//On affecte null
    ttobj2d = NULL;
  }
  
}


void ZoneAffichage::set_taille(int t)
{
	//On affecte la taille
  my_taille = t;
}




void ZoneAffichage::zoom (double z){
	
	Polygonne * poly2d;
	Polyedre * poly3d_2;
	poly3d_2 = new Polyedre;
	//On aloue a la bonne taille
	poly2d = new Polygonne[poly3d.nbface];
	//On lance le zoom
	zoompoly(poly3d,z);
	//On lance le backfaceculling
	poly3d_2 = backfaceculling(poly3d);
	//On tri
	tripolyedre(*poly3d_2);
	//On transforme en 2d
	poly2d = to2d3d(poly3d_2);
	//On change la taille
	my_taille = poly3d_2->nbface;
	//On copie le polygone dans le tab d'objet2d
	for(int i=0 ; i<poly3d_2->nbface ; i++){  
		ttobj2d[i] = &poly2d[i];
	}
	
	//On delete le polyedre temporaire
	delete poly3d_2;
	 
}


void ZoneAffichage::move (double x,double y){
	
	Polygonne * poly2d;
	Polyedre * poly3d_2;
	poly3d_2 = new Polyedre;
	//On aloue a la bonne taille
	poly2d = new Polygonne[poly3d.nbface];
	//On lance le zoom
	movepoly(poly3d,x,y);
	//On lance le backfaceculling
	poly3d_2 = backfaceculling(poly3d);
	//On tri
	tripolyedre(*poly3d_2);
	//On transforme en 2d
	poly2d = to2d3d(poly3d_2);
	//On change la taille
	my_taille = poly3d_2->nbface;
	//On copie le polygone dans le tab d'objet2d
	for(int i=0 ; i<poly3d_2->nbface ; i++){  
		ttobj2d[i] = &poly2d[i];
	}
	
	//On delete le polyedre temporaire
	delete poly3d_2;
	 
}
