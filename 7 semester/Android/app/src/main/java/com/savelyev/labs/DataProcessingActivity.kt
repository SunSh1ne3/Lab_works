package com.savelyev.labs

import android.content.Context
import android.content.Intent
import android.content.SharedPreferences
import android.os.Bundle
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import android.util.Log

const val APP_PREFERENCES = "mysettings"
const val APP_PREFERENCES_login = "login_user"
const val APP_PREFERENCES_phone = "phone_user"
const val APP_PREFERENCES_password = "password_user"
const val APP_PREFERENCES_checkbox = "checkbox_user"

class DataProcessingActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_data_processing)
        val storage = getSharedPreferences(APP_PREFERENCES, Context.MODE_PRIVATE)


        if (ReadDataUser(storage)) {
            if (GetDataCheckBox(storage)) {
                startActivity(Intent(this,ContentActivity::class.java))
            }
            else{
                startActivity(Intent(this,LoginActivity::class.java))
            }
        }
        else {
            startActivity(Intent(this,RegistrationActivity::class.java))

        }

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


fun AddDataString(storage: SharedPreferences,TypeData: String, Data: String){
    storage.edit().putString(TypeData, Data).apply()
}

fun AddDataBoolean(storage: SharedPreferences,TypeData: String, Data: Boolean){
    storage.edit().putBoolean(TypeData, Data).apply()
}
