package com.savelyev.labs

import android.os.Bundle
import android.view.View
import androidx.appcompat.app.AppCompatActivity
import androidx.navigation.NavController
import androidx.navigation.Navigation
import androidx.navigation.ui.setupWithNavController
import com.google.android.material.bottomnavigation.BottomNavigationView

class ContentActivity : AppCompatActivity() {

    private lateinit var navController: NavController

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_content)

        setupBottomNavigationBar()


    }

    private fun setupBottomNavigationBar() {
        val bottom_nav = findViewById<BottomNavigationView>(R.id.bottom_nav)
        navController = Navigation.findNavController(this, R.id.nav_host_fragment)
        bottom_nav.setupWithNavController(navController)
        hideNavBars(bottom_nav)
    }

    private fun hideNavBars(bottom_nav: BottomNavigationView) {
        navController.addOnDestinationChangedListener { _, destination, _ ->
            when (destination.id) {
                R.id.splashFragment -> {
                    bottom_nav.visibility = View.GONE
                }

                R.id.loginFragment -> {
                    bottom_nav.visibility = View.GONE
                }

                R.id.registrationFragment -> {
                    bottom_nav.visibility = View.GONE
                }

                else -> {
                    bottom_nav.visibility = View.VISIBLE
                }
            }
        }

    }
}
