#ifndef SFML_PLOT_GRID_H
#define SFML_PLOT_GRID_H
#define SFML_NO_DEPRECATED_WARNINGS

#include <SFML/Graphics.hpp>
#include <vector>

namespace sf {
namespace plot {

class Grid : public Drawable, public Transformable {
private:
  /// means that cut the grid in kPart
  static const int kPart = 4;

public:
  ////////////////////////////////////////////////////////////
  /// \brief constructor
  ////////////////////////////////////////////////////////////
  Grid();
  ////////////////////////////////////////////////////////////
  /// \brief setup once the grid shape
  ///
  /// \param size grid size
  ////////////////////////////////////////////////////////////
  void setup(const Vector2f &size);

private:
  ////////////////////////////////////////////////////////////
  /// \brief sfml method for drawing
  ////////////////////////////////////////////////////////////
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  /// grid lines
  sf::VertexArray vertices_;

  /// grid borders
  sf::RectangleShape border_;

  /// grid color
  sf::Color color_;

  /// keep the size
  sf::Vector2f size_;
};

} // namespace plot
} // namespace sf

#endif // SFML_PLOT_GRID_H
