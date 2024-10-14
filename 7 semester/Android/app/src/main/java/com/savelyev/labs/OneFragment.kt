package com.savelyev.labs

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView

class OneFragment : Fragment() {

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