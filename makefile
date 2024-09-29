a.out: 
	g++ main.cpp      	        	\
		GrLib/GrLib.cpp         	\
		MVC/systemState.cpp 		\
		MVC/model.cpp             	\
		MVC/view.cpp              	\
		objects/object.cpp      	\
		objects/molecular.cpp      	\
		vectors/vector.cpp  		\
		vectors/vectorDec.cpp 		\
		vectors/vectorPol.cpp 		\
		-lsfml-graphics -lsfml-window -lsfml-system \
