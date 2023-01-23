//
//  ArUco-OpenGL.cpp
//
//  Created by Jean-Marie Normand on 28/02/13.
//  Copyright (c) 2013 Centrale Nantes. All rights reserved.
//


#include "ArUco-OpenGL.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2\calib3d.hpp>

// Constructor
ArUco::ArUco(string intrinFileName, float markerSize) {
   // Initializing attributes
   m_IntrinsicFile= intrinFileName;
   m_MarkerSize   = markerSize;
   // read camera parameters if passed
   m_CameraParams.readFromXMLFile(intrinFileName);
  
}

// Destructor
ArUco::~ArUco() {}

void ArUco::resizeCameraParams(cv::Size newSize) {
	m_CameraParams.resize(newSize);
}

// Detect marker and draw things
void ArUco::doWork(Mat inputImg) {
   m_InputImage   = inputImg;
   m_GlWindowSize = m_InputImage.size();
   m_CameraParams.resize(m_InputImage.size());
   resize(m_GlWindowSize.width, m_GlWindowSize.height);
}

// Draw axis function
void ArUco::drawAxis(float axisSize) {
   // X
   glColor3f (1,0,0);
   glBegin(GL_LINES);
   glVertex3f(0.0f, 0.0f, 0.0f); // origin of the line
   glVertex3f(axisSize,0.0f, 0.0f); // ending point of the line
   glEnd( );
   
   // Y
   glColor3f (0,1,0);
   glBegin(GL_LINES);
   glVertex3f(0.0f, 0.0f, 0.0f); // origin of the line
   glVertex3f(0.0f, axisSize, 0.0f); // ending point of the line
   glEnd( );
   
   // Z
   glColor3f (0,0,1);
   glBegin(GL_LINES);
   glVertex3f(0.0f, 0.0f, 0.0f); // origin of the line
   glVertex3f(0.0f, 0.0f, axisSize); // ending point of the line
   glEnd( );
}

void ArUco::drawWireCube(GLdouble size) {
    drawBox(size, GL_LINE_LOOP);
}

// Fonction qui dessine un cube de différentes manières (type)
void ArUco::drawBox(GLfloat size, GLenum type)
{
		static const GLfloat n[6][3] =
		{
		  {-1.0, 0.0, 0.0},
		  {0.0, 1.0, 0.0},
		  {1.0, 0.0, 0.0},
		  {0.0, -1.0, 0.0},
		  {0.0, 0.0, 1.0},
		  {0.0, 0.0, -1.0}
		};
		static const GLint faces[6][4] =
		{
		  {0, 1, 2, 3},
		  {3, 2, 6, 7},
		  {7, 6, 5, 4},
		  {4, 5, 1, 0},
		  {5, 6, 2, 1},
		  {7, 4, 0, 3}
		};
		GLfloat v[8][3];
		GLint i;

		v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
		v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
		v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
		v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
		v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
		v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;

		for (i = 5; i >= 0; i--) {
			glBegin(type);
			glNormal3fv(&n[i][0]);
			glVertex3fv(&v[faces[i][0]][0]);
			glVertex3fv(&v[faces[i][1]][0]);
			glVertex3fv(&v[faces[i][2]][0]);
			glVertex3fv(&v[faces[i][3]][0]);
			glEnd();
		}
}


bool ArUco::loadOBJ(
	const char* path,
	std::vector <Vec3d>& out_vertices,
	std::vector <Vec2d>& out_uvs,
	std::vector <Vec3d>& out_normals) {

	std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
	std::vector< Vec3d > temp_vertices;
	std::vector< Vec2d > temp_uvs;
	std::vector< Vec3d > temp_normals;

	FILE* file = fopen(path, "r");
	if (file == NULL) {
		printf("Impossible to open the file !\n");
		return false;
	}
	while (1) {
		char lineHeader[256];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF) {
			break; // EOF = End Of File. Quit the loop.
		// else : parse lineHeader
		}
		if (strcmp(lineHeader, "v") == (char)0) {
			Vec3d vertex;
			fscanf(file, "%f %f %f\n", &vertex[0], &vertex[1], &vertex[2]);
			temp_vertices.push_back(vertex);
		}
		else if (strcmp(lineHeader, "vt") == 0) {
			Vec2d uv;
			fscanf(file, "%f %f\n", &uv[0], &uv[1]);
			temp_uvs.push_back(uv);
		}
		else if (strcmp(lineHeader, "vn") == 0) {
			Vec3d normal;
			fscanf(file, "%f %f %f\n", &normal[0], & normal[1], & normal[2]);
			temp_normals.push_back(normal);
		}
		else if (strcmp(lineHeader, "f") == 0) {
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
				int matches = fscanf(file, "%d//%d %d//%d %d//%d\n", &vertexIndex[0],  &normalIndex[0], &vertexIndex[1], &normalIndex[1], &vertexIndex[2], &normalIndex[2]);
				if (matches == 6) {
					vertexIndices.push_back(vertexIndex[0]);
					vertexIndices.push_back(vertexIndex[1]);
					vertexIndices.push_back(vertexIndex[2]);
					normalIndices.push_back(normalIndex[0]);
					normalIndices.push_back(normalIndex[1]);
					normalIndices.push_back(normalIndex[2]);		
				}
				else {
					cout << "error of match" << endl;
				}


			// For each vertex of each triangle
			for (unsigned int i = 0; i < vertexIndices.size(); i++) {
				unsigned int vertexIndex = vertexIndices[i];
				if (temp_vertices.size() > vertexIndex - 1) {
					Vec3d vertex = temp_vertices[vertexIndex - 1];
					out_vertices.push_back(vertex);
				}


				if (temp_uvs.size() > vertexIndex - 1) {
					Vec2d uv = temp_uvs[vertexIndex - 1];
					out_uvs.push_back(uv);
				}


				if (temp_normals.size() > vertexIndex - 1) {
					Vec3d normals = temp_normals[vertexIndex - 1];
					out_normals.push_back(normals);
				}

			}
		}

	}

}


// GLUT functionnalities

// Drawing function
void ArUco::drawScene() {
   // If we do not have an image we don't do anyhting
   if (m_ResizedImage.rows==0)
      return;
   
   // On "reset" les matrices OpenGL de ModelView et de Projection
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   // On deinit une vue orthographique de la taille de l'image OpenGL
   glOrtho(0, m_GlWindowSize.width, 0, m_GlWindowSize.height, -1.0, 1.0);
   // on definit le viewport correspond a un rendu "plein ecran"
   glViewport(0, 0, m_GlWindowSize.width , m_GlWindowSize.height);

   // on desactive les textures
   glDisable(GL_TEXTURE_2D);

   // On "flippe" l'axe des Y car OpenCV et OpenGL on un axe Y inverse pour les images/textures
   glPixelZoom( 1, -1);

   // On definit la position ou l'on va ecrire dans l'image
   glRasterPos3f(0, m_GlWindowSize.height, -1.0f);
   
   // On "dessine" les pixels contenus dans l'image OpenCV m_ResizedImage (donc l'image de la Webcam qui nous sert de fond)
   glDrawPixels (m_GlWindowSize.width, m_GlWindowSize.height, GL_RGB, GL_UNSIGNED_BYTE, m_ResizedImage.ptr(0));
   
   // On active ensuite le depth test pour les objets 3D
   glEnable(GL_DEPTH_TEST);
   
   // On passe en mode projection pour definir la bonne projection calculee par ArUco
   glMatrixMode(GL_PROJECTION);
   double proj_matrix[16];
   m_CameraParams.glGetProjectionMatrix(m_ResizedImage.size(),m_GlWindowSize,proj_matrix,0.01,100);
   glLoadIdentity();
   // on charge la matrice d'ArUco 
   glLoadMatrixd(proj_matrix);
   
   // On affiche le nombre de marqueurs (ne sert a rien)
   double modelview_matrix[16];
   std::cout << "Number of markers: " << m_Markers.size() << std::endl;
   
   // On desactive le depth test
   glDisable(GL_DEPTH_TEST);

   // Pour chaque marqueur detecte
   for (unsigned int m=0;m<m_Markers.size();m++)
   {
	   // On recupere la matrice de modelview qui correspond au marqueur [m]
       m_Markers[m].glGetModelViewMatrix(modelview_matrix);
       glMatrixMode(GL_MODELVIEW);
       glLoadIdentity();
	   // on charge cette matrice pour se placer dans le repere de ce marqueur [m] 
       glLoadMatrixd(modelview_matrix);
      
      // On dessine les axes X Y Z
      drawAxis(m_MarkerSize);

      // On se deplace sur Z de la moitie du marqueur pour dessiner "sur" le plan du marqueur
      //glTranslatef(0, 0, m_MarkerSize/2.);
     
	  // On sauvegarde la matrice courante
      glPushMatrix();
	  // on choisit une couleur
	  //glColor3f(1, 0.4f, 0.4f);

	  //On dessine une cube en fil de fer
      //drawWireCube( m_MarkerSize );

      // Ajouter votre code ici !!
	  // Read our .obj file
	  /*
	  if (!loaded) {
		  cout << "loading..." << endl;
		  loadOBJ("E:\\OBJ\\TriSimplR.obj", vertices, uvs, normals);
		  loaded = true;
		  cout << "loaded : " << vertices.size()<< endl << "____________________________" << endl;
	  }

	  vector<Vec3d> verticeMov;
	  for (int j = 0; j < vertices.size(); j++) {
		  Vec3d vert;
		  vert[0] = vertices[j][0] *m_MarkerSize / 2.;
		  vert[1] = vertices[j][1] * m_MarkerSize / 2.;
		  vert[2] = (vertices[j][2] +1) * m_MarkerSize / 2.;
		  verticeMov.push_back(vert);
	  }

	  for (int j = 0; j < vertices.size()-2; j += 3) {
		  glBegin(GL_TRIANGLES);
		  glColor3d(1, 0, 0);
		  glNormal3d(normals[j][0], normals[j][1], normals[j][2]);
		  glVertex3d(verticeMov[j][0], verticeMov[j][1], verticeMov[j][2]);
		  glNormal3d(normals[j + 2][0], normals[j + 2][1], normals[j + 2][2]);
		  glVertex3d(verticeMov[j + 2][0], verticeMov[j + 2][1], verticeMov[j + 2][2]);
		  glNormal3d(normals[j+1][0], normals[j+1][1], normals[j+1][2]);
		  glVertex3d(verticeMov[j+1][0], verticeMov[j+1][1], verticeMov[j+1][2]);
		  glEnd();
	  }
	  */

	  if (!loaded) {
		  cout << "loading..." << endl;
		  chat.Load("C:\\Users\\Eleve\\Downloads\\aruco\\Aruco3112MiniOpenGL\\catR.obj");
		  renard.Load("C:\\Users\\Eleve\\Downloads\\aruco\\Aruco3112MiniOpenGL\\fox.obj");
		  loaded = true;
		  cout << "loaded :  ____________________________" << endl;
	  }

	  if (m_Markers[m].id == 217) {
		  glColor3d(0.8, 0.35, 0.2);
		  renard.Draw();
	  }

	  if (m_Markers[m].id == 144) {
		  glColor3d(0.9, 0.9, 0.9);
		  chat.Draw();
	  }



      // On re=charge la matrice que l'on a sauvegarde
      glPopMatrix();
   }
   // Desactivation du depth test
   glDisable(GL_DEPTH_TEST);
}



// Idle function
void ArUco::idle(Mat newImage) {
   // Getting new image
   m_InputImage = newImage.clone();
  
   // Undistort image based on distorsion parameters
   m_UndInputImage.create(m_InputImage.size(),CV_8UC3);
   
   //transform color that by default is BGR to RGB because windows systems do not allow reading BGR images with opengl properly
   cv::cvtColor(m_InputImage,m_InputImage,cv::COLOR_BGR2RGB);
   
   //remove distorion in image ==> does not work very well (the YML file is not that of my camera)
   //cv::undistort(m_InputImage,m_UndInputImage, m_CameraParams.CameraMatrix, m_CameraParams.Distorsion);
   m_UndInputImage = m_InputImage.clone();
   
   //resize the image to the size of the GL window
   cv::resize(m_UndInputImage,m_ResizedImage,m_GlWindowSize);

   //detect markers
   m_PPDetector.detect(m_ResizedImage, m_Markers, m_CameraParams, m_MarkerSize, false);

}

// Resize function
void ArUco::resize(GLsizei iWidth, GLsizei iHeight) {
   m_GlWindowSize=Size(iWidth,iHeight);
   
   //not all sizes are allowed. OpenCv images have padding at the end of each line in these that are not aligned to 4 bytes
   if (iWidth*3%4!=0) {
      iWidth+=iWidth*3%4;//resize to avoid padding
      resize(iWidth, m_GlWindowSize.height);
   }
   else {
      //resize the image to the size of the GL window
      if (m_UndInputImage.rows!=0)
         cv::resize(m_UndInputImage, m_ResizedImage, m_GlWindowSize);
   }

}

// Test using ArUco to display a 3D cube in OpenCV
void ArUco::draw3DCube(cv::Mat img, int markerInd) {
   if(m_Markers.size() > markerInd) {
      aruco::CvDrawingUtils::draw3dCube(img, m_Markers[markerInd], m_CameraParams); 
   }
}

void ArUco::draw3DAxis(cv::Mat img, int markerInd) {
   if(m_Markers.size() > markerInd) {
      aruco::CvDrawingUtils::draw3dAxis(img, m_Markers[markerInd], m_CameraParams); 
   }
   
}
