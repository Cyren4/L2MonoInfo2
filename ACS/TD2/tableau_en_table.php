<?php
// function tableau_en_table($tab, $str){
//     if (count($tab) < 1)
//         return "";
// }

// function cherche_index_n($tab, $nb){
//     if (count($tab) < $nb)
//         return False;
//     $i=0;
//     while ($i < $nb) {
//         array_shift($tab);
//         $i++;
//     }
//     return  array_shift($tab);
// }




//1. 
function tableau_en_table($tab, $caption)
{
  if (!$tab) return '';
  $chaine = "";
  foreach($tab as $k => $v)
    $chaine .= "<tr>\n<td>$k</td>\n<td>$v</td>\n</tr>\n";
  $th = "<tr>\n<th>Nom</th>\n<th>Valeur</th>\n</tr>\n";
  return "<table>\n<caption>$caption</caption>\n$th$chaine$th</table>\n";
}

//2.
function cherche_index_n($tab, $n)
{
    foreach($tab as $k => $v) {
        if (!--$n) return $k;
    }
    return false;
}

/* // tests
$Scores = array("candidatA"=>130,"candidatB"=>300,"candidatC"=>30);
echo tableau_en_table($Scores, 'scores'), "\n";
echo cherche_index_n($Scores, 2), "\n";
/*/
?>