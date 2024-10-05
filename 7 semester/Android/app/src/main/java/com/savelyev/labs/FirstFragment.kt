package com.savelyev.labs

import android.annotation.SuppressLint
import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.findFragment
import androidx.navigation.findNavController
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView

class FirstFragment : Fragment() {

    private val myApdater = PhonesApdater()

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val root = inflater.inflate(R.layout.fragment_first, container, false)

        loadData()
        root.findViewById<RecyclerView>(R.id.recyclerView).layoutManager = LinearLayoutManager(requireContext())
        root.findViewById<RecyclerView>(R.id.recyclerView).adapter = myApdater

        return root
    }

    private fun loadData(){
        myApdater.setupPhones(PhonesData.phonesArr)
    }

}