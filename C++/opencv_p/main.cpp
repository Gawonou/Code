
#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
  // Charger une image
  cv::Mat image = cv::imread("Gawono.jpg");
  if (image.empty()) {
    std::cerr << "Erreur lors du chargement de l'image !" << std::endl;
    return -1;
  }

  // Afficher l'image dans une fenêtre
  cv::imshow("Image", image);

  // Attendre une touche pour fermer
  cv::waitKey(0);
  return 0;
}
