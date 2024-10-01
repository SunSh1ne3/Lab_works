package com.savelyev.labs

import android.content.Context
import android.content.Intent
import android.content.SharedPreferences
import android.os.Bundle
import android.os.Handler
import android.widget.Button
import android.widget.CheckBox
import android.widget.EditText
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity


class LoginActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_login)

        // Для хранилища (если можно как-то ее сделать общую для всех, будет круто)
        val storage = getSharedPreferences(APP_PREFERENCES, Context.MODE_PRIVATE)

        //Поля
        val enter_field = findViewById<EditText>(R.id.EmailField)
        val password_field = findViewById<EditText>(R.id.PasswordField)
        val checkbox = findViewById<CheckBox>(R.id.AutoEnterCheckBox)

        //Кнопка входа
        val enter_btn = findViewById<Button>(R.id.EnterButton)

        enter_btn.setOnClickListener {
            if (CheckField(storage, enter_field.text.toString(), password_field.text.toString())){
                if(GetDataCheckBox(storage) != checkbox.isChecked){
                    AddDataBoolean(storage, APP_PREFERENCES_checkbox, checkbox.isChecked)
                }

                startActivity(Intent(this,ContentActivity::class.java))
            }
            else{
                ShowToast("Неверный логин и пароль")
            }
        }



    }

    fun ShowToast(Error: String){
        Toast.makeText(this, Error, Toast.LENGTH_SHORT).show()
    }

    fun CheckField(storage: SharedPreferences, enter_field: String, password_field: String): Boolean{

        val storage_login = storage.getString(APP_PREFERENCES_login, "");
        val storage_phone = storage.getString(APP_PREFERENCES_phone, "");
        val storage_password = storage.getString(APP_PREFERENCES_password, "");



        return (storage_login == enter_field && storage_password == password_field) ||
                (storage_phone == enter_field && storage_password == password_field)

    }
}