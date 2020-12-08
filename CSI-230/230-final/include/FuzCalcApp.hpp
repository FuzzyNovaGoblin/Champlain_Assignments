/**
 * @file FuzCalcApp.hpp
 * @author Grant Hedley (FuzzyNovaGoblin@fuzytech.com)
 * @brief defines wrapper class for GTK::Application
 * @version 0.1
 * @date 2020-12-07
 */
#if !defined(FUZCALCAPP_HPP)
#define FUZCALCAPP_HPP

#include <gtkmm/application.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>

#include <FuzCalcWin.hpp>

namespace FuzCalc {

class FuzCalcApp {
   Glib::RefPtr<Gtk::Application> mApp;     // GTK aplication object
   CalcWin*                    mWindow;  // GTK window object pointer

public:
   /**
	 * @brief Construct a new FuzCalcApp object
	 * @param id: the id of the application defaults to "com.fuzytech.fuzcalc"
	 */
   FuzCalcApp(std::string id = "com.fuzytech.fuzcalc");

   /**
	 * @brief Destroy the Fuz Calc App object
	 */
   ~FuzCalcApp();

   /**
	 * @brief start start the GTK::Application [mApp] with [mWindow]
	 * @return int the return status of teh application, 0 if sucess
	 */
   int start();
};

}  // namespace FuzCalc

#endif  // FUZCALCAPP_HPP
