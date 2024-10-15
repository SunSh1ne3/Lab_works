package com.savelyev.labs

import android.content.Context
import android.content.Intent
import android.os.Bundle
import android.text.InputType
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import android.widget.Toast
import androidx.navigation.fragment.NavHostFragment

class RegistrationFragment : Fragment() {
    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val root = inflater.inflate(R.layout.fragment_registration, container, false)
        //val navController = NavHostFragment.findNavController(this)
        val storage = requireActivity().getSharedPreferences(APP_PREFERENCES, Context.MODE_PRIVATE)

        val by_phone_Text = root.findViewById<TextView>(R.id.OnPhoneText)
        val by_email_Text = root.findViewById<TextView>(R.id.OnEmailText)
        val enter_field = root.findViewById<EditText>(R.id.EmailField)
        val password_field = root.findViewById<EditText>(R.id.PasswordField)
        val repeat_password_field = root.findViewById<EditText>(R.id.RepeatPasswordField)
        val registration_button = root.findViewById<Button>(R.id.RegistrationButton)


        // Обработка нажатия кнопки "По почте"
        by_email_Text.setOnClickListener {
            by_phone_Text.setTextColor(resources.getColor(R.color.white, null))
            by_email_Text.setTextColor(resources.getColor(R.color.green, null))

            enter_field.text.clear()
            enter_field.setHint(R.string.enter_email)
            enter_field.inputType = InputType.TYPE_TEXT_VARIATION_EMAIL_ADDRESS
        }

        // Обработка нажатия кнопки "По номеру"
        by_phone_Text.setOnClickListener {
            by_email_Text.setTextColor(resources.getColor(R.color.white, null))
            by_phone_Text.setTextColor(resources.getColor(R.color.green, null))

            enter_field.text.clear()
            enter_field.setHint(R.string.enter_phone)
            enter_field.inputType = InputType.TYPE_CLASS_PHONE
        }

        // Обработка нажатия кнопки "Зарегестрироваться"
        registration_button.setOnClickListener {
            // Проверка, что тосты не вылезли
            if(CheckFields(enter_field, password_field, repeat_password_field)){
                if(enter_field.text.isNotEmpty()){
                    // Проверка на тип поля (Мыло\телефон)
                    if (ThisFieldIsMail(enter_field)){
                        AddDataString(storage, APP_PREFERENCES_login, enter_field.text.toString())
                    }
                    else{
                        AddDataString(storage, APP_PREFERENCES_phone, enter_field.text.toString())
                    }
                }
                if(password_field.text.isNotEmpty()){
                    AddDataString(storage, APP_PREFERENCES_password, password_field.text.toString())
                }

                // Если данные записались
                if(ReadDataUser(storage)){
                    startActivity(Intent(requireContext(),ContentActivity::class.java))
                    //navController.navigate(R.id.)
                }
            }

        }

        return root
    }

    private fun ShowToast(Error: String){
        Toast.makeText(requireContext(), Error, Toast.LENGTH_SHORT).show()
    }

    private fun CheckFields(EnterField: EditText,PasswordField: EditText, RepeatPasswordField: EditText): Boolean{
        when {
            ThisFieldIsMail(EnterField) && !EnterField.text.contains("@") && EnterField.text.isNotEmpty() -> {
                ShowToast(resources.getString(R.string.msg_error_Mail))
                return false
            }

            !ThisFieldIsMail(EnterField) && !EnterField.text.contains("+") && EnterField.text.isNotEmpty() -> {
                ShowToast(resources.getString(R.string.msg_error_PlusInNumber))
                return false
            }

            PasswordField.text.length in 1..7 -> {
                ShowToast(resources.getString(R.string.msg_error_SizePassword))
                return false
            }

            PasswordField.text.toString() != RepeatPasswordField.text.toString() -> {
                ShowToast(resources.getString(R.string.msg_error_MismatchPassword))
                return false
            }
            true -> {
                return true
            }
        }
        return true

    }

    private fun ThisFieldIsMail(EnterField: EditText): Boolean{
        return EnterField.hint.toString() == resources.getString(R.string.enter_email)
    }
}