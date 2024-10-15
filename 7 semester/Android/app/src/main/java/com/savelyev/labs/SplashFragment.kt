package com.savelyev.labs

import android.content.Context
import android.content.SharedPreferences
import android.os.Bundle
import android.util.Log
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.navigation.fragment.NavHostFragment

const val APP_PREFERENCES = "mysettings"
const val APP_PREFERENCES_login = "login_user"
const val APP_PREFERENCES_phone = "phone_user"
const val APP_PREFERENCES_password = "password_user"
const val APP_PREFERENCES_checkbox = "checkbox_user"

class SplashFragment : Fragment() {
    override fun onCreateView(inflater: LayoutInflater,
                              container: ViewGroup?,
                              savedInstanceState: Bundle?): View? {
        val root =  inflater.inflate(R.layout.fragment_splash, container, false)
        val navController = NavHostFragment.findNavController(this)
        val storage = requireActivity().getSharedPreferences(APP_PREFERENCES, Context.MODE_PRIVATE)

        if (ReadDataUser(storage)) {
            if (GetDataCheckBox(storage)) {
                navController.navigate(R.id.oneFragment)
            }
            else {
                navController.navigate(R.id.loginFragment)
            }
        }
        else {
            navController.navigate(R.id.registrationFragment)
        }
        return root
    }
}

fun ReadDataUser(storage: SharedPreferences): Boolean {
    //storage.edit().clear().apply()
    Log.i("DebugInfo", storage.all.toString())
    return (storage.contains(APP_PREFERENCES_login) or storage.contains(APP_PREFERENCES_phone))
            && storage.contains(APP_PREFERENCES_password)
}

fun GetDataCheckBox(storage: SharedPreferences): Boolean {
    return storage.getBoolean(APP_PREFERENCES_checkbox, false)
}


fun AddDataString(storage: SharedPreferences, TypeData: String, Data: String){
    storage.edit().putString(TypeData, Data).apply()
}

fun AddDataBoolean(storage: SharedPreferences, TypeData: String, Data: Boolean){
    storage.edit().putBoolean(TypeData, Data).apply()
}