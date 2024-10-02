a.out: 
	g++ main.cpp      	        		\
		GrLib/GrLib.cpp         		\
		MVC/controllerMolecule.cpp  	\
		MVC/modelMolecule.cpp       	\
		MVC/viewMolecule.cpp        	\
		MVC/MVC_Button/modelButton.cpp  \
		MVC/MVC_Button/viewButton.cpp   \
		objects/object.cpp      		\
		objects/molecule.cpp      		\
		objects/wall.cpp         		\
		objects/button.cpp         		\
		vectors/vector.cpp  			\
		vectors/vectorDec.cpp 			\
		vectors/vectorPol.cpp 			\
		-lsfml-graphics -lsfml-window -lsfml-system \
