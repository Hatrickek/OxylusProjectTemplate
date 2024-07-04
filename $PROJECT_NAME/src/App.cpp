#include <Core/EntryPoint.hpp>
#include <Core/App.hpp>

#include "$PROJECT_NAMELayer.hpp"

#include <filesystem>

namespace ox {
class $PROJECT_NAMEApp : public ox::App {
public:
  $PROJECT_NAMEApp(const ox::AppSpec& spec) : App(spec) { }
};

App* create_application(const AppCommandLineArgs& args) {
  AppSpec spec;
  spec.name = "$PROJECT_NAME";
  spec.working_directory = std::filesystem::current_path().string();
  spec.command_line_args = args;
  spec.assets_path = "Assets";

  const auto app = new $PROJECT_NAMEApp(spec);
  app->push_layer(new $NAMESPACE::$PROJECT_NAMELayer());

  return app;
}
}