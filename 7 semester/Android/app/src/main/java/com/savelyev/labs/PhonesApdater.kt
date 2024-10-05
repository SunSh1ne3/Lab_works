package com.savelyev.labs
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView

class PhonesApdater: RecyclerView.Adapter<RecyclerView.ViewHolder>() {
    private var mPhonesList: ArrayList<PhoneModel> = ArrayList()

    fun setupPhones(phonesList: Array<PhoneModel>){
        mPhonesList.clear()
        mPhonesList.addAll(phonesList)
        notifyDataSetChanged()
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): RecyclerView.ViewHolder {
        var layoutInflater = LayoutInflater.from(parent.context)
        val itemView = layoutInflater.inflate(R.layout.recycleview_item, parent, false)
        return PhonesViewHolder(itemView)
    }

    override fun onBindViewHolder(holder: RecyclerView.ViewHolder, position: Int) {
       if (holder is PhonesViewHolder){
           holder.bind(mPhones = mPhonesList[position])
       }
    }

    override fun getItemCount(): Int {
       return mPhonesList.count()
    }

}
class PhonesViewHolder(itemView: View): RecyclerView.ViewHolder(itemView){

    fun bind(mPhones: PhoneModel){
        itemView.findViewById<TextView>(R.id.NamePhone).text = mPhones.name
        itemView.findViewById<TextView>(R.id.PricePhone).text = mPhones.price
        itemView.findViewById<TextView>(R.id.DatePhone).text = mPhones.date
        itemView.findViewById<TextView>(R.id.ScorePhone).text = mPhones.score
    }
}

